#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

#define MAX 30000

signed main(){
    int n;
    cin >> n;
    vector<int> ans;
    int t, sum = 0;
    for(int i = 1; i <= MAX; i++){
        if(ans.size() == n - 2){
            t = i;
            break;
        }
        if(i % 2 == 0 || i % 3 == 0 || i % 5 == 0){
            ans.emplace_back(i);
            sum += i;
        }
    }
    for(int i = t; i <= MAX; i++){
        if(i % 2 == 0 || i % 3 == 0 || i % 5 == 0){
            for(int j = i + 1; j <= MAX; j++){
                if(j % 2 == 0 || j % 3 == 0 || j % 5 == 0){
                    if((sum + i + j) % 30 == 0){
                        ans.emplace_back(i);
                        ans.emplace_back(j);
                        goto fin;
                    }
                }
            }
        }
    }
    fin:;
    rep(i,n){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}