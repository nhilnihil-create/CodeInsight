#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

const double PI=acos(-1.0);

int N; vll A;
void input()
{
    cin>>N;
    for(int i=0;i<N;++i){
        ll a; cin>>a; A.emplace_back(a);
    }
}

ll gcd(ll a, ll b)
{
    ll c=a%b;
    while(c!=0){
        a=b; b=c; c=a%b;
    }
    return b;
}

void solve()
{
    ll ans=gcd(A[0],A[1]);
    for(int i=2;i<N;++i){
        ans=gcd(ans,A[i]);
        if(ans==1) break;
    }
    cout<<ans<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}