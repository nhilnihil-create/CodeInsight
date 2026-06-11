#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>

#include <unordered_map>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e9;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(int i = 0; i < n; i++)
#define RREP(i, n) for(int i = n - 1; i >= 0; i--)
#define REP2(i, n, k) for(int i = 0; i < n; i += k)


int main() {
    string s;
    int x, y;
    
    cin >> s;
    scanf("%d %d", &x, &y);
    
    int xx = 0, yy = 0, d[8005] = {}, p = 0;
    bool yoko = true;
    REP(i, s.size()){
        if(s[i] == 'F'){
            d[p]++;
            if(yoko){
                xx++;
            }
            else{
                yy++;
            }
        }
        else{
            yoko = !yoko;
            p++;
        }
    }
    
    unordered_map<int, bool> dp1, dp2, dp3;
    dp1[d[0]] = true;dp2[0] = true;
    for(int i = 1; i <= p; i++){
        if(i % 2 == 0){
            if(d[i]){
                for(int j = -xx; j <= xx; j++){
                    if(dp1[j - d[i]] || dp1[j + d[i]]){
                        dp3[j] = true;
                    }
                }
                
                for(int j = min(-xx, -yy); j <= max(xx, yy); j++){
                    if(dp3[j]){
                        dp1[j] = true;
                    }
                    else{
                        dp1[j] = false;
                    }
                    dp3[j] = false;
                }
            }
        }
        else{
            if(d[i]){
                for(int j = -yy; j <= yy; j++){
                    if(dp2[j - d[i]] || dp2[j + d[i]]){
                        dp3[j] = true;
                    }
                }
                
                for(int j = min(-xx, -yy); j <= max(xx, yy); j++){
                    if(dp3[j]){
                        dp2[j] = true;
                    }
                    else{
                        dp2[j] = false;
                    }
                    dp3[j] = false;
                }
            }
        }
    }
    
    /*
    for(int i = -xx; i <= xx; i++){
        cout << dp1[i] << ' ';
    }
    cout << endl;
    for(int i = -yy; i <= yy; i++){
        cout << dp2[i] << ' ';
    }
    cout << endl;
    */
    
    if(dp1[x] & dp2[y]){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}