#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int A,B,C,X;cin>>A>>B>>C>>X;

    int ans=0;
    _rep(a,A,0){
        _rep(b,B,0){
            _rep(c,C,0){
                if(a*500+b*100+c*50==X) ans++;
            }
        }
    }

    cout<<ans<<endl;
}