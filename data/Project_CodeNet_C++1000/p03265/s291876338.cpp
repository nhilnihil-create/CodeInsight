#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <complex>
#define ll long long
#define ld long double
#define F first
#define S second
#define Tsetso ios_base::sync_with_stdio(0) ; cin.tie(0) ;
#define pi acos(-1)
#define X real()
#define Y imag()
#define angle(a) (atan2((a).imag(),(a).real()))
#define vec(a,b) ((b)-(a))
#define lenght(a) (hypot((a).imag(),(a).real()))
#define normalize(a) (a)/length(a)
#define point complex<long double>
#define dP(a,b)((conj(a)*(b)).real())
#define cP(a,b)((conj(a)*(b)).imag())
#define same(p1,p2)  (dP(vec(p1,p2),vec(p1,p2)) < EPS)
#define lengthsqr(p)   dP(p,p)
#define rotate0(p,ang)  ((p)*exp(point(0,ang)))
#define rotataA(p,ang,about) (rotate0(vec(about,p),ang)+about)
#define reflect0(v,m) (conj((v)/(m))*(m))
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const ld EPS = (1e-10);
using namespace std;
using namespace __gnu_pbds;
const ll N = 2e5+50, inf = 1e3+5, mod = 1e9+7, NN = 1e5+10;
int Floor(double num)
{
    if ( num > 0.0 )
        return floor(num + 0.5);
    else
        return -1.0 * floor(fabs(num) + 0.5);
}
int main()
{
    double x1, y1, x2, y2 ;
    cin >> x1 >> y1 >> x2 >> y2 ;
    point a = {x1,y1}, b = {x2,y2} ;
    point c = rotataA(a,3*pi/2.0,b);
    cout << Floor(c.real()) << " " << Floor(c.imag()) << " " ;
    double z = c.imag(), zz = c.real() ;
    cout << Floor(zz - x2 + x1) << " " << Floor(z - y2 + y1);
}
