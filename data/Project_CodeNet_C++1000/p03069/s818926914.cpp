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
  int N;
  string S;
  cin >> N >> S;
  int W = count(S.begin(),S.end(),'.'),B = count(S.begin(),S.end(),'#');
  int WC = 0,BC = 0,ans = min(N-W,N-B);
  for(int i = 0;i < N;i++){
    if(S[i] == '#')BC++;
    else WC++;
    ans = min(ans,BC+W-WC);
  }
  cout << ans << endl;
}