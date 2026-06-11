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
const int MAXM = 5e3+10;

priority_queue<int> pq;
vector<vector<int> > graph;
queue<int> que;

int tmp[MAXN];
int A[MAXN];
int B[MAXN];

void mysort(int *vv,int sz,int di)
{
    int idx = -1;

    for(int i=0;i<sz;i++){
        if(vv[i]>=(1<<di)){
            idx = i;
            break;
        }
    }

    if(idx==-1)return;

    for(int i=idx;i<sz;i++)
        vv[i]%=(1<<di);

    int i=0,j=idx;
    int id = 0;

    for(int i=0;i<sz;i++)
        tmp[i] = 0;

    while(i<idx&&j<sz){
        if(vv[i]<=vv[j]){
            tmp[id] = vv[i];
            id++; i++;
        }
        else {
            tmp[id] = vv[j];
            id++; j++;
        }
    }

    if(i<idx){
        for(;i<idx;i++,id++)
            tmp[id] = vv[i];
    }
    if(j<sz){
        for(;j<sz;j++,id++)
            tmp[id] = vv[j];
    }

    for(int i=0;i<sz;i++)
        vv[i] = tmp[i];

    return;
}


int main()
{
    int n,m,k,a,b,x,y,q;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;
    int tc;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int i=0;i<n;i++)
        cin>>B[i];

    sort(A,A+n);
    sort(B,B+n);

    int res = 0;

    int bx,by;

    for(int di = 28; di >=0 ;di--){

        x = n-1,y = n-1;
        bx = (1<<di),by = (1<<(di+1));

        for(int i=0;i<n;i++){
            while(x>=0&&B[x]+A[i]>=bx)x--;
            while(y>=0&&B[y]+A[i]>=by)y--;
            if((y-x)&1)res^=(1<<di);
        }

        x = n-1,y = n-1;
        bx = (1<<di)+(1<<(di+1)),by = (1<<(di+2));

        for(int i=0;i<n;i++){
            while(x>=0&&B[x]+A[i]>=bx)x--;
            while(y>=0&&B[y]+A[i]>=by)y--;
            if((y-x)&1)res^=(1<<di);
        }
        mysort(A,n,di);
        mysort(B,n,di);
    }

    cout<<res<<"\n";

    return 0;
}
