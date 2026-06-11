#include <bits/stdc++.h>
//A
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
        ///memset   ///regular use
inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b);}
inline ll lcm(ll a, ll b) { return a * b / gcd(a, b);}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, p;
    cin>>a>>p;
    a*=3;
    a+=p;
    a/=2;
    cout<<a<<"\n";

}
