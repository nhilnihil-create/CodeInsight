#include <bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()
#define ini(x,y) memset(x,y,sizeof(x))
#define cauto const auto &
#define cint const int &
#define F(x, y, z) for (int x = y; x <= z; x++)
#define D(x, y, z) for (int x = y; x >= z; x--)
using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = static_cast<int>(1e5 + 25);
inline int read()
{
  int x = 0, y = 1, c = getchar();
  while (c > '9' || c < '0')
  {
    if (c == '-')
    {
      y = -1;
    }
    c = getchar();
  }
  while (c >= '0' && c <= '9')
  {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * y;
}
/*
 * 用最短的时间取得胜利！！！！
*/
struct road{
    int to,v;
    road(int to=0,int v=0):to(to),v(v){}
};

static vector<road> edge[MAXN];
struct heapnode{
    int to,val;
    heapnode(int T=0,int V=0):to(T),val(V){}
    bool operator<(const heapnode r)const{
        return val>r.val;
    }
};
static priority_queue<heapnode> q;
static int d[MAXN];
void dijkstra(){
    ini(d,0x3f);
    d[0]=0;
    q.push(heapnode(0,0));
    while(!q.empty()){
        int pos=q.top().to;
        q.pop();
        for(auto to:edge[pos]){

            if(d[pos]+to.v<d[to.to]){
                d[to.to]=d[pos]+to.v;//cout<<pos<<" "<<to.to<<" "<<d[to.to]<<endl;
                q.push(heapnode(to.to,d[to.to]));
            }
        }
    }
}
signed main(){
    int k=read();
    F(i,1,k-1){
        int now=i;
        F(j,1,9){
            edge[(i+j)%k].push_back(road(i,j));
            now*=10;
            edge[now%k].push_back(road(i,0));
        }
    }
    dijkstra();
//    int minn=INF;
    printf("%lld",d[1]+1);
    return 0;
}
