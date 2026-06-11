#include<cstdio>
#include<queue>
#include<utility>
#include<cstring>
#include<stack>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<map>
#define MAX_N 100001
#define INF_INT 2147483647
#define INF_LL 9223372036854775807
#define REP(i,n) for(int i=0;i<(int)(n);i++)
void init(int n);
int find(int n);
void unite(int x,int y);
bool same(int x, int y);
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
bool cmp_P(const P &a,const P &b){
  return a.second < b.second;
}

bool isOK(ll a, ll b){
  ll tmp;
  if(b % a == 0){
    tmp = b/a - 1;
  }else
    tmp = b/a;
  if(a <= tmp)
    return false;
  else
    return true;
}

ll cpair(ll a,ll b){
  if(b % a == 0){
    return b/a - 1;
  }else
    return b/a;
}

ll binary_search(ll key) {
    ll ng = -1; 
    ll ok = 10E10; 

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ng;
}

int main()
{
  ll a,b,res,tmp,d=0,Q,A[101],B[101];
  cin >> Q;
  REP(i,Q){
    cin >> A[i] >> B[i];
  }
  REP(i,Q){
    a = A[i];b = B[i];
    d = 0;
    if(a == 1 && b==1){
      cout << "0" << endl;
      continue;
    }
    res = binary_search(a*b);
    tmp = cpair(res,a*b);
    if(tmp == res){
      d++;
    }
    if(a <= res || b <= res)d++;
    cout << 2*binary_search(a*b) - d << endl;
  }
  return 0;
}


int par[MAX_N];
int ranks[MAX_N];

//n要素で初期化
void init(int n){
  REP(i,n){
    par[i] = i;
    ranks[i] = 0;
  }

}

//木の根を求める
int find(int x){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

void unite(int x,int y){
  x = find(x);
  y = find(y);
  if(x == y) return ;
  if(ranks[x] < ranks[y]){
    par[x] = y;
  }else{
    par[y] = x;
    if(ranks[x] == ranks[y]) ranks[x]++;
  }
}

bool same(int x, int y){
  return find(x) == find(y);
}

