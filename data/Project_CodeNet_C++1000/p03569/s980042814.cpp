#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    string S;
    cin >> S;
    // 両端から見ていく
    int l=0;
    int r=S.size()-1;
    ll ans=0;
    while(r-l>0){
        if(S[l]==S[r]){
            l++;
            r--;
            continue;
        }
        if(S[l]=='x'){
            ans++;
            l++;
        }else if(S[r]=='x'){
            ans++;
            r--;
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}