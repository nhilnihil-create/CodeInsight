#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define         pb         push_back
#define         sf(x)      scanf("%d",&x)
#define         sfl(x)     scanf("%lld",&x)
#define         pf(x)      printf("%d\n",x)
#define         pfl(x)     printf("%lld\n",x)
#define         endl       '\n'
#define         pii        pair<int,int>
#define         mapii      map<int,int>
#define         mapll      map<ll,ll>
#define         mapci      map<char,int>
#define         mapcl      map<char,ll>
#define         mapsi      map<string,int>
#define         mapsl      map<string,ll>
#define         pll        pair<ll,ll>
#define         vi         vector<int>
#define         vl         vector<ll>
#define         vd         vector<double,double>
#define         all(c)     c.begin(),c.end()
#define         F          first
#define         S          second
#define         mp         make_pair
#define        ftc(x)      cerr << #x << ": " << x << " " << endl;
#define         PI         acos(-1)
#define         lcm(a,b)   ((a*b)/__gcd(a,b))
#define        optimize    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define        sqr(a)       ((a)*(a))

int main()
{
ll i,j,k,l,m,n,q,p1,p2,q1,q2,x,ans,l1,l2,l3,l4,l5,l6,l7,l8;

cin >> n  >> m >> q;

ll s[n+10];
ll t[m+10];

for(i=0;i<n;i++)cin >> s[i];
for(i=0;i<m;i++)cin >> t[i];

while(q--)
{
    cin >> x ;

    q1 = upper_bound(s,s+n,x)-s;
    if(q1)q1--;
    q2 = upper_bound(s,s+n,x)-s;
    if(q2==n)q2--;

    p1 = upper_bound(t,t+m,x)-t;
    if(p1)p1--;
    p2 = upper_bound(t,t+m,x)-t;
    if(p2==m)p2--;

    q1 = s[q1] , q2 = s[q2] , p1 = t[p1] , p2 = t[p2];

    l1 = abs(x-q1) + abs(q1-p1);
    l2 = abs(x-q1) + abs(q1-p2);
    l3 = abs(x-q2) + abs(q2-p1);
    l4 = abs(x-q2) + abs(q2-p2);

    l5 = abs(x-p1) + abs(q1-p1);
    l6 = abs(x-p2) + abs(q1-p2);
    l7 = abs(x-p1) + abs(q2-p1);
    l8 = abs(x-p2) + abs(q2-p2);

    ans = min({l1,l2,l3,l4,l5,l6,l7,l8});

    cout << ans << endl;


}

}
