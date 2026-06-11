#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define lp(i,a,n) for(int i=a;i<=n;++i)
#define lpd(i,a,n) for(int i=a;i>=n;--i)
#define mem(a,b) memset(a,b,sizeof a)
#define all(v) v.begin(),v.end()
#define println(a) cout <<(a) <<endl
#define sz(x) ((int)(x).size())
#define readi(x) scanf("%d",&x)
#define read2i(x,y) scanf("%d%d",&x,&y)
#define read3i(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define mod 1000000007
#define eps 1e-8
#define infi 1000000000
#define infll 1000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef set<int> si;
typedef map<int,int> mii;

const int N = 200002;
int n,a[N],b[N];

int main(){
    readi(n);
    lp(i,1,n){
        int l,r;
        read2i(l,r);
        ++a[l+N/2], ++b[r+N/2];
    }

    ++a[0+N/2], ++b[0+N/2];

    lp(i,1,N-1) b[i] += b[i-1];
    lpd(i,N-2,0) a[i] += a[i+1];

    ll ans = 0;
    lp(i,0,N-2) ans += min(b[i], a[i+1]);
    cout <<2*ans;
}

/*
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
*/
