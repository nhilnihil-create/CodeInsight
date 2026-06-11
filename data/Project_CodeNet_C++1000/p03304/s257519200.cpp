#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define res(n) resize(n)
#define rev(v) reverse(v.begin(),v.end())
#define sor(v) sort(v.begin(),v.end())
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define vector ve
#define priority_queue pq
using namespace std;
typedef long long ll;


int main()
{
    ll n,m,d;
    cin >> n >> m >> d;

    double ans = 0;

    ll a = 0;
    if (d == 0) a = n;
    else if(1+d <= n-d) a = 2*d + (n-2*d)*2;
    else a = (n+1-(1+d)) + (n-d);

    //out(a);


    ans = (double(m)-1)/double(n)/double(n)*a;
    cout << fixed << setprecision(10);
    out(ans);

    return 0;
}
