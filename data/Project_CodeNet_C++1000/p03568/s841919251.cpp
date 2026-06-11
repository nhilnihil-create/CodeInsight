#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    int n;cin>>n;
    ll ans=pow(3,n);
    int ecnt=0;
    rep(i,n){
        int tmp;cin>>tmp;
        if(tmp%2==0)ecnt++;
    }
    ans -= pow(2,ecnt);
    co(ans);
}