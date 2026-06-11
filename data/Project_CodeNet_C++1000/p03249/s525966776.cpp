#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a;i < b;i++)
#define For(i, a) FOR(i, 0, a)
#define REV(i, a, b) for(int i = b-1;i >= a;i--)
#define Rev(i, a) REV(i, 0, a)
#define REP(a) For(i, a)
#define DEBUG_PRINT(...) fprintf(stderr, __VA_ARGS__)
#ifdef ENABLE_DEBUG
#define DEBUG(a) cerr<<#a<<"="<<a<<endl
#define DEBUG_ARRAY(a,n) cerr<<#a<<"["<<n<<"]="<<a[n]<<endl
#else
#define DEBUG(a) 
#define DEBUG_ARRAY(a,n) 
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
void print_pair(pi a){
  cerr<<"("<<a.first<<", "<<a.second<<") ";
}
template<int T1, int T2>
void print_2d(int a[T1][T2], int x, int y){
  For(i, x){
    For(j, y){
      cerr<<a[i][j]<<" ";
    }
    cerr<<endl;
  }
}
template<class T>
void print_array(T a[],size_t n){
  cerr<<"array:";
  REP(n-1)cerr<<a[i]<<",";
  cerr<<a[n-1]<<endl;
}

int N;
pll D[100000];
ll d[100000];
int childnumD[100000];
vector<ll> ans[100000];
ll dfs(ll index,ll depth){
  ll ret = 0;
  DEBUG(index);
  for(auto&& i : ans[index])
  {
    DEBUG(i);
    ret+=depth+1;
    ret+=dfs(i,depth+1);
  }
  return ret;
}
int main(){
  cin>>N;
  REP(N){
    ll tmp;
    cin>>tmp;
    D[i]=pll(tmp,i+1);
  }
  sort(D,D+N,greater<pll>());
  REP(N){
    d[i]=D[i].first;
    DEBUG(d[i]);
  }
  for (int i = 0; i < N-1; i++) {
    ll tmp=d[i]-(N-2)+2*childnumD[i];
    DEBUG(tmp);
      auto itr=lower_bound(d,d+N,tmp,greater<ll>());
      DEBUG(*itr);
      if(itr==d+N||*itr!=tmp){
        cout<<-1<<endl;
        return 0;
      }
      ans[itr-d].push_back(i);
      childnumD[itr-d]++;
      childnumD[itr-d]+=childnumD[i];
  }
  if(dfs(N-1,0)!=d[N-1]){
    DEBUG(dfs(N-1,0));
    cout<<-1<<endl;
    return 0;
  }
  For(j,N){
    DEBUG(j);
  for(auto&& i : ans[j])
  {
    DEBUG(i);
    cout<<D[j].second<<" "<<D[i].second<<endl;
  }
  }
  
  return 0;
}

