/*
    -ensure correct output format
    -ensure printing required output
    -reread the problem statement
  */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>pll;
typedef pair<ll,pair<ll,ll>>plll;
#define fastread() (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define vll(v) v.begin(),v.end()
#define all(x) x.rbegin(),x.rend()
#define min3(a, b, c)   min(a, min(b, c))
#define max3(a, b, c)   max(a, max(b, c))
#define F first
#define S second
#define in  freopen("input.txt", "r", stdin)
#define out  freopen("output.txt", "w", stdout)
#define minheap int,vector<int>,greater<int>
#define pb push_back
#define eb emplace_back
#define ischar(x)  (('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z'))
#define isvowel(ch) ((ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')||(ch=='A'|| ch=='E' || ch=='I'|| ch=='O'|| ch=='U'))
#define bug cout<<"BUG"<<endl;
const int Max = 1e6 + 10;
const int Mod = 1e9 + 7;
const double PI  =3.141592653589793238463;
bool compare(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
    return (a.first > b.first);
}
ll lcm(ll a,ll b)
{
    if(a==0 || b==0)return 0;

    return a/__gcd(a,b)*b;
}

void input(ll ara[],ll n)
{
    for(ll i=0; i<n; i++)cin>>ara[i];
}


vector<ll>adj[Max+10];
ll indeg[Max+10];

void addEdege(ll u,ll v)
{
    indeg[v]++;

    adj[u].eb(v);
}

ll cost[Max+10];

ll connect[Max+10];


ll topsort(ll s,ll last)
{


    queue<ll>q;

    q.push(s);

    cost[s]=1;

    ll u;

    while(!q.empty())
    {
        u=q.front();

        q.pop();

        for(auto v  : adj[u])
        {
            cost[v]=(cost[v]+cost[u])%Mod;

            indeg[v]--;

            if(!indeg[v])
                q.push(v);
        }
    }


    return cost[last]%Mod;
}

int main()
{

    fastread();

    ll i,j,p,n,m,a,sum=0,k,t,b,c,d,cnt=0,q,l,r;


    bool flag=true;




    ll id=1;

    cin>>n>>m;

    string str[n+2];

    for(i=0; i<n; ++i)
        cin>>str[i];

    indeg[1]=1;

    for(i=0; i<n; i++)
    {
        id=(m*i)+1;



        for(j=0; j<m; j++,id++)
        {
            if(str[i][j]=='.' && indeg[id])
            {


                if(j+1<m && str[i][j+1]=='.' )
                    addEdege(id,id+1);


                if(i+1<n && str[i+1][j]=='.' )
                {
                    addEdege(id,id+m);
                }

            }




        }
    }



    cout<<topsort(1,n*m)<<endl;











}
