#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 300005
#define INF 1000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P; //val,idx

int N;
ll A[SIZE];
P m1[SIZE],m2[SIZE];

void update(int S,P v){
  if(v == m1[S] || v == m2[S])return;
  if(v.first > m1[S].first){
    m2[S] = m1[S];
    m1[S] = v;
  }else if(m2[S].first < v.first && v.first <= m1[S].first){
    m2[S] = v;
  }
}

ll f(int S){
  return m1[S].first + m2[S].first;
}

int main(){
  cin >> N;
  rep(i,0,1<<N){
    cin >> A[i];
  }

  m1[0] = P(A[0],0);

  rep(S,0,1<<N){
    rep(i,0,N) if(S>>i & 1){
      int T = S & ~(1<<i);
      update(S,m1[T]);
      update(S,m2[T]);
      update(S,P(A[S],S));
    }
  }

  rep(K,1,1<<N){
    ll ans = f(K);
    rep(i,0,N) if(K>>i & 1){
      int T = (K & ~(1<<i)) | ((1<<i)-1);
      ans = max(ans,f(T));
    }
    cout << ans << endl;
  }

  return 0;
}
