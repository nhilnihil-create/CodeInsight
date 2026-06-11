#include <bits/stdc++.h>

typedef  long long ll;
typedef long double ld;
using namespace std;
const int N=1e5+5;

#define endl "\n"
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define point complex<double>
ll mod=1e9+7;
ll inf=2e18;
double eps=1e-10;
double pi=acos(-1);
double dot(point a, point b)
{
    return (conj(a)*b).real();
}
double cross(point a, point b)
{
    return (conj(a)*b).imag();
}
ll add(ll x, ll y)
{
    return (x%mod+y%mod)%mod;
}
point takepoint()
{
    int x, y;
    cin>>x>>y;
    point p(x,y);
    return p;
}
point rotatearound(point v, point o, double deg)
{
    v-=o;
    v*=polar((double)1,pi/2);
    v+=o;
    return v;
}
int main()
{

   point a=takepoint();
   point b=takepoint();
   point c=rotatearound(b,a,90);
   point d=c+b-a;
   cout<<fixed<<setprecision(0)<<d.real()<<" "<<d.imag()<<" "<<c.real()<<" "<<c.imag();



    return 0;
}
