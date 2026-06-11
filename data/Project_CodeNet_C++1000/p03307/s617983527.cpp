#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define all(v) v.begin(),v.end()
#define sz size()
#define mp make_pair
#define pb push_back
#define rep(p,a,b) for(ll p=a ; p<b ; p++)
#define F first
#define S second
using namespace std;

typedef vector <int> vi;
typedef pair< int, int > pii;


int main()
{
    ll t,i,j,k,ans,n;

    //cin>>t;
    t=1;
    while(t--)
    {
        cin>>n;
        if (n%2)cout<<n*2;
        else cout<<n;
    }
    
    return 0;
}
