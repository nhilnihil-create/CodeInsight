#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> vec(5);
    string str;
    rep(i,n){
        cin >> str;
        if(str[0] == 'M') vec[0]++;
        if(str[0] == 'A') vec[1]++;
        if(str[0] == 'R') vec[2]++;
        if(str[0] == 'C') vec[3]++;
        if(str[0] == 'H') vec[4]++;
    }
ll ans = 0;
    rep(i,5){
        reps(j,i+1,5){
            reps(k,j+1,5){
                ans += (vec[i] * vec[j] * vec[k]);
                //cout << i << " " << j << " " << k << endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
