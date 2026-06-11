#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using vc=vector<char>;
using vvc=vector<vc>;
using pii = pair<int,int>;
using pil = pair<int,ll>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  int N;
  cin >> N;
  
  vector<bool> is_prime(N+1, true);
  is_prime[0]=false; is_prime[1]=false;
  for(int i=2; i*i<=N; i++) {
    if(!is_prime[i]) continue;
    for(int j=2; i*j<=N; j++) is_prime[i*j]=false;
  }
  vi prime;
  rep(i,N+1) {
    if(is_prime[i]) prime.push_back(i);
  }
  
  int size=prime.size();
  int c2=0,c4=0,c14=0,c24=0,c74=0;
  vi ind(size);
  rep(i,size) {
    int num=N;
    while(num) {
      num/=prime[i];
      ind[i]+=num;
    }
    if(ind[i]>=2) {
      c2++;
      if(ind[i]>=4) {
        c4++;
        if(ind[i]>=14) {
          c14++;
          if(ind[i]>=24) {
            c24++;
            if(ind[i]>=74) c74++;
          }
        }
      }
    }
  }
  
  cout << c74+c24*(c2-1)+c4*(c4-1)/2*(c2-2)+c14*(c4-1) << endl;
}