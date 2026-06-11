#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
#define endl '\n'
#define max3(a,b,c) max(a,max(b,c))

const int q = 1e9+9;




int main()
{
    int n,b;
    cin>>n>>b;
    cout<<(n-1)*(b-1)<<endl;



    return 0;
}
    // gotcha;
