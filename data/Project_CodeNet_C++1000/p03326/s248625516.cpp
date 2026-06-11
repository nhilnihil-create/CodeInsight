#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define All(a) a.begin(),a.end()
#define INF 1000000007
const int MOD = 1000000007;
//accumulate(vec.begin(), vec.end(), 0)
//std::sort(v.begin(), v.end(), std::greater<Type>());
//set_intersection(x, x+7, y, y+6, back_inserter(v));
//set_union(x, x+7, y, y+6, back_inserter(v));
//set_difference(x, x+7, y, y+6, back_inserter(v));

int gcd(int x,int y){
  if(x%y==0) return y;
  else return gcd(y,x%y);
}

bool isPrime(int n){
  if(n < 2) return false;
  else if(n == 2) return true;
  else if(n%2==0) return false;

  for(int i=3;i<=sqrt(n);i++){
    if(n%i==0) return false;
  }
  return true;
}


/*
int main(){
  ll N,M;
  ll ans = 0;

  cin >> N >> M;
  vector<vector<ll>>cakes(N,vector<ll>(3));
  for(ll i=0;i<N;i++){
    cin >> cakes[i][0] >> cakes[i][1] >> cakes[i][2];
  }
  for(int bit=0;bit<(1<<N);bit++){
    ll cnt = 0;
    ll sx=0,sy=0,sz=0;
    for(ll i=0;i<N;i++){
      if(bit & (1<<i)){
        sx += cakes[i][0];
        sy += cakes[i][1];
        sz += cakes[i][2];
        cnt++;

      }
    }
    if(cnt==M)ans = max(ans,abs(sx)+abs(sy)+abs(sz));
  }
  cout<< ans <<endl;
}
*/

int N, M;

int main() {
    cin >> N >> M;
    vector<long long> a[3];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            long long num; cin >> num;
            a[j].push_back(num);
        }
    }
    long long res = 0;
    for (int bit = 0; bit < (1<<3); ++bit) {
        vector<long long> b;
        for (int i = 0; i < N; ++i) {
            long long tmp = 0;
            for (int j = 0; j < 3; ++j) {
                if (bit & (1<<j)) tmp += a[j][i];
                else tmp -= a[j][i];
            }
            b.push_back(tmp);
        }
        sort(b.begin(), b.end(), greater<long long>());
        long long sum = 0;
        for (int i = 0; i < M; ++i) {
            sum += b[i];
        }
        res = max(res, sum);
    }
    cout << res << endl;
}