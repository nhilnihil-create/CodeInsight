#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define pss pair<short,short>
#define piii  pair<pii,int>
#define vii vector<pair<int,int> >
#define st first
#define nd second
const int mod=1000000007;
const int inf=1000000009;
const long long int INF=1000000000000000009;
using namespace std;
int P[100001],T[100001],S[100001];
int pow(ll a,int b)
{
    ll wynik=1;
    if(b==0)
        return 1;
    while(b!=0)
    {
        if(b&1)
        {
            wynik*=a;
            wynik%=mod;
        }
        a*=a;
        a%=mod;
        b/=2;
    }
    return wynik;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&T[i]);
    for(int i=1;i<=n;i++)
        P[i]=pow((ll)i,mod-2);
    for(int i=1;i<=n;i++)
    {
        S[i]=S[i-1]+P[i];
        S[i]%=mod;
    }
    ll wynik=0;
    for(int i=1;i<=n;i++)
    {
        wynik+=(ll)S[i]*T[i]+(ll)(S[n-i+1]-S[1])*T[i];
        wynik+=(ll)mod*mod;
        wynik%=mod;
    }
    for(int i=2;i<=n;i++)
    {
        wynik*=i;
        wynik%=mod;
    }
    printf("%lld",wynik);
    return 0;
}
