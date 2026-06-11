#include <bits/stdc++.h>
using namespace std;
#ifdef ENABLE_DEBUG
#define dump(a) cerr<<#a<<"="<<a<<endl
#define dumparr(a,n) cerr<<#a<<"["<<n<<"]="<<a[n]<<endl
#else
#define dump(a) 
#define dumparr(a,n) 
#endif
#define FOR(i, a, b) for(int i = a;i < b;i++)
#define For(i, a) FOR(i, 0, a)
#define REV(i, a, b) for(int i = b-1;i >= a;i--)
#define Rev(i, a) REV(i, 0, a)
#define REP(a) For(i, a)

typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<ll,pll> ppll;
typedef vector<ll> vll;

const ll INF=(1LL<<50);

template<class S,class T>
std::ostream& operator<<(std::ostream& os,pair<S,T> a){
  os << "(" << a.first << "," << a.second << ")";
  return os;
}
template<class T>
std::ostream& operator<<(std::ostream& os,vector<T> a){
  os << "[ ";
  REP(a.size()){
    os<< a[i] << " ";
  }
  os<< " ]";
  return os;
}


void solve(long long N, long long K, long long Q, std::vector<long long> A){
  auto AA = A;
  sort(AA.begin(),AA.end());
  set<ll> a(A.begin(),A.end());
  ll ans=AA[Q-1]-AA[0];
  for(auto x:a){
    vector<vector<ll>::iterator> tmp;
    For(j,A.size()){
      if(A[j]<=x){
        tmp.push_back(A.begin()+j);
      }
    }
    tmp.push_back(A.end());
    vector<ll> prob;
    auto itr=A.begin();
    For(j,tmp.size()){
      vector<ll> t(itr,tmp[j]);
      ll tt=max(0LL,(ll)t.size()-K+1);
      if(tt!=0){
        sort(t.begin(),t.end());
        For(k,tt){
          prob.push_back(t[k]);
        }
      }
      if(tmp[j]!=A.end())
        itr=next(tmp[j]);
    }
    if(prob.size()>=Q){
      sort(prob.begin(),prob.end());
      ans=min(ans,prob[Q-1]-prob[0]);
    }else{
      break;
    }
  }
  cout<<ans<<endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    long long Q;
    scanf("%lld",&Q);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, K, Q, std::move(A));
    return 0;
}
