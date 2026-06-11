#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

const int MAX = 510000;
const int MOD = 1000000007;

int main(){
  int N , M; cin >> N >> M;
  vector<P1> a(M); rep(i,M) cin >> a[i].fi >> a[i].sc.fi; rep(i,M) a[i].sc.sc = i;
  SORT(a);

  vector<int> ans(M + 10);
  int cnt = 1;
  ans[0] = cnt;
  rep(i,M){
    if(a[i].fi == a[i + 1].fi) ans[i + 1] = ++cnt;
    else{
      cnt = 1;
      ans[i + 1] = cnt;
    }
  }

  vector<P1> tmp(M);
  rep(i,M){
    tmp[i].fi = a[i].sc.sc;
    tmp[i].sc.fi = a[i].fi;
    tmp[i].sc.sc = ans[i];
  }

  SORT(tmp);

  rep(i,M){
    printf("%06d", tmp[i].sc.fi);
    printf("%06d", tmp[i].sc.sc);
    cout << endl;
  }
}
