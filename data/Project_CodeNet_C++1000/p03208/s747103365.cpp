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
 int n,k;
 cin>>n>>k;
 for(int i=0;i<n;i++)
        cin>>arr[i];
 sort(arr,arr+n);
 int ans=1e9;
 for(int i=k-1;i<n;i++)
    ans=min(ans,arr[i]-arr[i-k+1]);
 cout<<ans;


    return 0;
}
