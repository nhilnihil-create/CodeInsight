#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
    ll A,B; cin>>A>>B;
    ll n1 = (A-2)/2+1;
    ll n2 = (B-1)/2+1;
    if(n1%2==1)n1=1;
    else n1=0;
    if(n2%2==1)n2=1;
    else n2=0;
    if((A-1)%2==0)n1 ^= (A-1);
    if(B%2==0)n2 ^= B;

    if(A==0)n1=0;
    if(B==0)n2=0;
    ll res = n1^n2;
    cout<<res<<endl;
}