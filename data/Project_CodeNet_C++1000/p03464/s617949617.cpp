#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 10000000000000000;
double PI = 3.1415926535;

ll ceiling(ll a,ll b){
  if(a % b == 0){
    return a / b;
  }else{
    return (a / b) + 1;
  }
}

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

int main(){
  ll K;cin >> K;
  vector<ll> A(K);
  for(ll i = 0;i < K;i++){
    cin >> A[i];
  }
  reverse(A.begin(),A.end());
  ll min = 2;
  ll max = 3;
  for(ll i = 0;i < K;i++){
    if(i == 0){
      if(A[i] != 2){
        cout << -1 << endl;
        return 0;
      }
    }else{
      if(max < A[i]){
        cout << -1 << endl;
        return 0;
      }
      min = ceiling(min,A[i]) * A[i];
      if(min > max){
        cout << -1 << endl;
        return 0;
      }
      max = (max / A[i]) * A[i] + (A[i]-1);
    }
  }
  cout << min << ' ' << max << endl;
}