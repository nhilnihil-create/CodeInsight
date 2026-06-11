#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n,q;
    string S;
    cin>>n>>q>>S;
    vector<int> a(n,0);
    for(int i=1;i<n;i++){
        if(S[i-1]=='A' && S[i]=='C'){
            a[i]=1;
        }
    }

    vector<int> s(n+1,0);
    rep(i,n) s[i+1]=s[i]+a[i];

    rep(i,q){
        int l,r;
        cin>>l>>r;
        l--;
        int ans=s[r]-s[l];
        if(l>=1){
            if(S[l-1]=='A' && S[l]=='C') ans--;
        }
        cout<<ans<<endl;
    }
}