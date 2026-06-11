#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <functional>
#include <map>
#include <queue>
#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)
using namespace std;
using ll = long long;
ll MOD = 1e9+7;


int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '2'){
            ans++;
        }
    }
    cout << ans << endl;
}
