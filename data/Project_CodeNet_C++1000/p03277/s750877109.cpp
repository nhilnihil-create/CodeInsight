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
const long long int INF=1000000000000000009;
const int mod=1000000007;
const int inf=1000000009;
using namespace std;
ll N;
int n;
int T[100005],S[100005],Z[100005],P[100005],D[600005];
ll I[200005];
int suma=1;
void dodaj(int u,int c)
{
    D[u]+=c;
    while(u!=1)
    {
        u/=2;
        D[u]=D[2*u]+D[2*u+1];
    }
}
int getsum(int a,int b,int lo,int hi,int u)
{
    if(b<=a)
        return 0;
    if(a==lo&&b==hi)
        return D[u];
    int mid=(lo+hi)/2;
    int L=getsum(a,min(b,mid),lo,mid,2*u);
    int P=getsum(max(a,mid),b,mid,hi,2*u+1);
    return L+P;
}
bool funkcja(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(T[i]<=x)
        {
            Z[i]=0;
            S[i]=S[i-1]+1;
        }
        else
        {
            Z[i]=1;
            S[i]=S[i-1]-1;
        }
       // printf("%d\n",S[i]);
        dodaj(S[i]+suma/2,1);
    }
    ll wynik=0;
    int ile=n;
    for(int i=1;i<=n;i++)
    {
        wynik+=getsum(ile+1,suma/2+2,1,suma/2+2,1);
      //  printf("%d %lld\n",ile,wynik);
        if(Z[i]==0)
            ile++;
        else
            ile--;
        dodaj(S[i]+suma/2,-1);
    }
   // printf("%lld\n",wynik);
    for(int i=1;i<=2*n;i++)
        I[i]=0;
    for(int i=1;i<=suma;i++)
        D[i]=0;
    if(wynik>=N)
        return true;
    return false;
}
int main()
{
    scanf("%d",&n);
    while(suma<2*n+1)
        suma*=2;
    suma*=2;
    suma--;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&T[i]);
        P[i]=T[i];
    }
    sort(P+1,P+n+1);
    N=(ll)n*(n+1)/2;
    N/=2;
    N++;
   // printf("%lld\n",N);
    int p=0,k=n;
    S[0]=n;
    while(p+1<k)
    {
        int sr=(p+k)/2;
        if(funkcja(P[sr]))
            k=sr;
        else
            p=sr;
    }
    printf("%d",P[k]);

    return 0;
}
