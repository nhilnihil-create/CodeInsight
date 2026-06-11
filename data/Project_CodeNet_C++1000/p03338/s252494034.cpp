#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    string S;
    cin >> N >> S;
    ll ans = 0;
    for(int i=1;i<N;i++){
        string S1 = S.substr(0,i);
        string S2 = S.substr(i,N-i);
        map<char,int> memo,memo2;
        ll tmp = 0;
        for(int j=0;j<i;j++){
            if(memo[S1[j]]==0){
                memo[S1[j]]++;
                for(int k=0;k<S2.size();k++){
                    if(S2[k]==S1[j]){
                        if(memo2[S2[k]]==0){
                            memo2[S2[k]]++;
                            tmp++;
                        }
                    }
                }
            }
        }
        ans = max(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}