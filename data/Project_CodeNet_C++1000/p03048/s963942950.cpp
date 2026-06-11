#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    int r,g,b,n;cin>>r>>g>>b>>n;
    int rmax=n/r,gmax=n/g;
    ll ans = 0;
    for(int i=0;i<=rmax;i++){
        for(int j=0;j<=gmax;j++){
            if((n-r*i-g*j)>=0&&((n-r*i-g*j)%b==0))ans++;
        }
    }
    co(ans);
}
