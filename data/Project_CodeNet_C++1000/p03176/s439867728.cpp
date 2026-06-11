#include <bits/stdc++.h>
using namespace std;

#define fori(i,a,b)    for(int i=a;i<=b;i++)
#define ford(i,a,b)   for(int i=a;i>=b;i--)
#define all(a)        a.begin(), a.end()
#define in(c,x)       ((c).find(x) != (c).end())
#define isp(c,x)      (find(all(c),x) != (c).end())
#define pb             push_back
#define ppb            pop_back
#define sz(x)          (int)x.size()
#define fill(a,v)      memset(a, v, sizeof a)
#define fs first
#define sc second
#define ub upper_bound
#define lb lower_bound
#define en '\n'

typedef long long int lli;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef pair< int, int > pii;
typedef pair< lli, lli > plli;
typedef list<int> li;
typedef map<int, int> mi;
typedef map<lli, lli> mlli;
lli gcd(lli a,lli b){return (!b)?a:gcd(b,a%b);}
int t = 1; int ti;


struct FT{
    int N;
    vector<lli> ft;

    void init(int n){
        N = n;
        ft.assign(n + 1, 0);
    }

    void updateMax(int idx, lli val){
        while(idx <= N)	{
            ft[idx] = max(ft[idx], val);
            idx += idx & -idx;
        }
    }

    lli prefMax(lli idx){
        lli ans = 0;

        while(idx > 0)	{
            ans = max(ans, ft[idx]);
            idx -= idx & -idx;
        }

        return ans;
    }

};



const int N = 2e5 + 5;
lli h[N], a[N], n;

void solve(){
    cin>>n;

    fori(i, 1, n)
    cin>>h[i];

    fori(i, 1, n)
    cin>>a[i];

    FT cml;
    cml.init(n);

    lli ans = 0;

    fori(i, 1, n){
        lli val = cml.prefMax(h[i]-1);
        cml.updateMax(h[i], val + a[i]);
    }

    cout<<cml.prefMax(n);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // cin>>t;

    // for(ti= 1; ti <= t; ti++)
    solve();

//    cout<<"\nTHINK OF SPECIAL CASES, ARRAY LIMITS, LLI vs INT, 1LL";
}
