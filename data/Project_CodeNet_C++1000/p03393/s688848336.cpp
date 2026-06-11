#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    string S;
    cin >> S;
    if(S=="zyxwvutsrqponmlkjihgfedcba"){
        cout << -1 << endl;
        return 0;
    }
    map<char,int> m,m2;
    rep(i,S.size()){
        m[S[i]]++;
    }
    if(m.size()<26){
        string ans = S;
        for(char c='a';c<='z';c++){
            if(m[c]==0){
                ans+=c;
                cout << ans << endl;
                return 0;
            }
        }
    }else{
        for(int i=25;i>0;i--){
            if(S[i]>S[i-1]){
                string ans = S.substr(0,i-1);
                rep(i,ans.size()){
                    m2[ans[i]]++;
                }
                for(char c=S[i-1]+1;c<='z';c++){
                    if(m2[c]==0){
                        ans+=c;
                        break;
                    }
                }
                cout << ans << endl;
                return 0;
            }
        }
    }
    return 0;
}