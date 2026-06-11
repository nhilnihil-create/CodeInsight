#include <bits/stdc++.h>
const int INF=1e9,MOD=1e9+7;
using namespace std;
#define int long long
//template
#define N {cout<<"No"<<endl;continue;}
#define Y {cout<<"Yes"<<endl;continue;}
//main
signed main(){
  int T;cin>>T;
  std::vector<int> a(T),b(T),c(T),d(T);
  for(int i=0;i<T;i++)cin>>a[i]>>b[i]>>c[i]>>d[i];
  for(int i=0;i<T;i++){
    int A=a[i],B=b[i],C=c[i],D=d[i];
    if(A<B||D<B)N
    if(C>=B-1)Y
    int g=__gcd(B,D);
    C-=A%g;B-=A%g;
    int t=(B-1)/g;
    if(C<t*g)N
    Y
  }
}
