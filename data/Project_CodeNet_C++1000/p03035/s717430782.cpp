#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "
int main(){
    int a,b;cin>>a>>b;
    if(a<=5)co(0);
    else if(a>=6&&a<=12)co(b/2);
    else co(b);
}
