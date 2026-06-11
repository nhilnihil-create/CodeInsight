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

int arr[N];
int main()
{
    ll n,k;
    cin>>n>>k;
    n--,k--;
    ll ans=n/k+(n%k!=0);
    cout<<ans;

    return 0;
}
