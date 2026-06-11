#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

int main(){
    int n,q;
    string s;
    cin>>n>>s>>q;
    rep(r,q){
        int k;
        cin>>k;
        ll ans=0,d=0,m=0,dm=0;
        rep(i,n){
            if(0<=i-k){
                if(s[i-k]=='D'){
                    --d;
                    dm-=m;
                }
                else if(s[i-k]=='M'){
                    --m;
                }
            }
            if(s[i]=='D'){
                ++d;
            }
            else if(s[i]=='M'){
                ++m;
                dm+=d;
            }
            else if(s[i]=='C'){
                ans+=dm;
            }
        }
        cout<<ans<<endl;
    }
}
