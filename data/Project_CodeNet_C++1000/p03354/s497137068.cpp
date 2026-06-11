#include <bits/stdc++.h>

using namespace std;

#define lp(i,n) for(int i = 0; i <n;i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define MP make_pair
#define SZ(v) ((int)((v).size()))
typedef long long ll;

const ll MOD = 1e9 + 7;
const int OO = (int)1e6;
const int N = (int)1e7;

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
struct union_find
{
    vector<int>parent;
    vector<int>rank;
    int forest;
    union_find(int n){
        parent = vector<int>(n+1);
        rank   = vector<int>(n+1);
        forest = n;
        for(int i=1;i<=n;i++){
            parent[i]=i;
            rank[i]=1;
        }
    }
    int find_parent(int child){
        if(child==parent[child])return parent[child];
        return parent[child]=find_parent(parent[child]); 
    }
    int merge(int x,int y){
        if(rank[x]>rank[y])swap(x,y);
        parent[x]=y;
        if(rank[x]==rank[y])rank[y]++;
    }
    bool union_set(int x,int y){
        x = find_parent(x),y=find_parent(y);
        if(x!=y){
            merge(x,y);
            forest--;
        }
        return x!=y;
    }
};
int a[N];
int main() {
	#   ifdef LOCAL_PROJECT
        freopen("in.txt", "r", stdin);
    #   endif
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int x,y;
    union_find uf = union_find(n);
    for(int i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        uf.union_set(a[x],a[y]);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(uf.find_parent(a[i])==uf.find_parent(i))ans++;
    }
    printf("%d",ans);
    
    return 0;
}