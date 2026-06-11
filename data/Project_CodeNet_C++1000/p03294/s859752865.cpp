#include<bits/stdc++.h>
#define ll long long int
#define Y printf("YES\n")
#define N printf("NO\n")
#define mp make_pair
#define pb push_back
#define tp make_tuple
#define sc(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define pr(a) printf("%lld\n",a)
using namespace std;

int main()
{
    ll n,i,j,k,l,p,q,t,x,y;

    sc(n);

    k=0;

    for(i=0;i<n;i++){

        cin>>x;
        k+=(x-1);
    }

    cout<<k<<endl;
}