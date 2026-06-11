#include <bits/stdc++.h>
#define f first
#define s second
#define MOD 1000000007
#define PMOD 998244353
#define pb(x) push_back(x)
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> plii;
typedef pair<int, pii> piii;
const int INF = 1e9+10;
const ll LINF = 1LL*INF*INF;
const int MAXN = 2e5+10;
const int MAXM = 2e3+10;

priority_queue<int> pq;
vector<vector<int> > graph;
queue<int> que;

int A[MAXN];
char S[MAXN];

vector<int> P;
vector<int> tot;

int main()
{
    int n,m,k,a,b,x,y,q;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;

    cin>>n>>k>>q;

    for(int i=1;i<=n;i++)
        cin>>A[i];

    vector<int> val;

    for(int i=1;i<=n;i++)
        val.push_back(A[i]);

    sort(val.begin(),val.end());

    val.erase(unique(val.begin(),val.end()),val.end());

    for(int i=0;i<val.size();i++){

        cur = val[i];
        tot.clear();
        P.clear();

        for(int i=1;i<=n;i++){
            if(A[i]>=cur)P.push_back(A[i]);
            else {
                sort(P.begin(),P.end());

                m = P.size();

                for(int i=0;i<m-k+1;i++)
                    tot.push_back(P[i]);
                P.clear();
            }
        }
        sort(P.begin(),P.end());
        m = P.size();
        for(int i=0;i<m-k+1;i++)
            tot.push_back(P[i]);

        sort(tot.begin(),tot.end());

        if((int)tot.size()<q)break;

        mn = min(mn,tot[q-1]-cur);
    }

    cout<<mn<<"\n";

    return 0;
}
