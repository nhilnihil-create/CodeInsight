#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vpll vector < pair<long long,long long> >
#define fill(a,val)  memset(a,val, sizeof (a))
#define sort_unique(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(cont) cont.begin(), cont.end()
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MAX   1e9
#define MIN  -1e9
typedef map<int,int> mpi;
typedef set<int> seti;
typedef multiset<int> mseti;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define rep(i, n)    for(long long int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define repn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define trav(a, x) for(auto& a : x)
struct Interval {int start, end;};
bool compare(Interval i1, Interval i2) {return (i1.start < i2.start);}
vll adj[100005];
int main()
{
    string s;
    cin>>s;
    ll n=s.size();
    ll c=0;
    rep(i,s.size()-1){
        if(s[i]!=s[n-i-2])
            c=1;
    }
    if(s[0]=='0'||s[n-1]=='1'||c==1){
        cout<<-1;
        return 0;
    }
    ll last=1;
    rep(i,s.size()-1){
        if(s[i]=='1'){
            adj[last].pb(i+2);
            last=i+2;
        }
        else
            adj[last].pb(i+2);
    }
    repA(i,1,n){
        rep(j,adj[i].size())
        cout<<i<<" "<<adj[i][j]<<"\n";
    }
    return 0;
}
