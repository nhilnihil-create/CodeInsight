#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 90000000000000000;
int PI = 3.1415926535;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<pair<ll,ll>>>;

int main(){
  ll N,K;cin >> N >> K;
  ll ans = 0;
  ll z = 0;
  for(int i = K+1;i <= N;i++){
    //cout << '(' << i << ')' << N % i << ' ';
    ans += N / i * (i - K);
    //cout << N / i * (i - K) << ' ';
    if(N % i != 0 && K != 0){
      ans += max(z,N % i - K + 1);
      //cout << max(N % i - K + 1,z);
    }
    if(N % i != 0 && K == 0){
      ans += max(z,N % i - K );
      //cout << max(N % i - K ,z);
    }
    //cout << endl;
  }
  cout << ans << endl;
}

