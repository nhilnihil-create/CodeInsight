#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "
int main(){
    int r,d,x;cin>>r>>d>>x;
    rep(i,10){
        x = r*x -d;
        co(x);
    }
}
