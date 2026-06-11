#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 100000000;
double PI = 3.1415926535;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<pair<ll,ll>>>;

int main(){
  int N,K;
  cin >> N >> K;
  if(1+ (K-1) * 2 <= N){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}