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
int T[200005];
ll S[200005],D[200005];
int main()
{
    int n,x;
    scanf("%d %d",&n,&x);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&T[i]);
        S[i]=S[i-1]+T[i];
    }
    ll wynik=INF;
    D[1]=5;
    D[2]=5;
    for(int i=3; i<=n; i++)
        D[i]=D[i-1]+2;
    for(int i=1; i<=n; i++)
    {
        ll aktual=(ll)x*n;
        aktual+=(ll)i*x;
        int ile=n;
        int wsk=1;
        while(ile>0)
        {
            if(aktual>wynik)
                break;
            if(S[ile]-S[max(0,ile-i)]>INF/(ll)D[wsk])
                break;
            aktual+=(ll)D[wsk]*(S[ile]-S[max(0,ile-i)]);
            wsk++;
            ile-=i;
        }
        wynik=min(wynik,aktual);
    }
    printf("%lld",wynik);
    return 0;
}
