#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
#define max(a,b) a > b ? a : b

int main(){
    int n,m;
    cin >> n >> m;
    int num[10] = {0,2,5,5,4,5,6,3,7,6};
    vector<int> flag(m);

    rep(i,m) cin >> flag[i];
    sort(flag.begin(),flag.end(),greater<int>());
    vector<int> dp(n+10,-1e9);
    dp[0] = 0;


    rep(i,n+1){
        rep(j,m){
            dp[i+num[flag[j]] ] = max(dp[i+num[flag[j]] ], dp[i] + 1); 
        }
    }

    int cnt = n;
    vector<int> num_cnt(10,0);
    while(cnt > 0){
        rep(j,m){
            if(cnt-num[flag[j]] < 0) continue;

            if(dp[cnt-num[flag[j]]] == dp[cnt] - 1){
                num_cnt[flag[j]]++;
                cnt -= num[flag[j]];
                break;
            }
        }
    }

    for(int i = 9; i > 0; i--){
        rep(j,num_cnt[i]){
            cout << i;
        }
    }
    cout << endl;
    return 0;
}
