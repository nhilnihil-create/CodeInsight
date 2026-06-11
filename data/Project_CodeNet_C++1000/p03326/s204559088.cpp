#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N;
  int M;
  cin >> N >> M;
  vector<vector<ll>> v(8, vector<ll>(N, 0));
  for(int i = 0; i < N; i++){
    ll a,b,c;
    cin >> a >> b >> c;
    v.at(0).at(i) =  a+b+c;
    v.at(1).at(i) = -a+b+c;
    v.at(2).at(i) =  a-b+c;
    v.at(3).at(i) = -a-b+c;
    v.at(4).at(i) =  a+b-c;
    v.at(5).at(i) = -a+b-c;
    v.at(6).at(i) =  a-b-c;
    v.at(7).at(i) = -a-b-c;
  }

  ll max_val = 0;
  for(int i = 0; i < 8; i++){
    sort(v.at(i).rbegin(), v.at(i).rend());
    ll tmp = 0;
    for(int j = 0; j < M; j++){
      tmp += v.at(i).at(j);
    }
    max_val = max(tmp, max_val);
  }

  cout << max_val << endl;

  

}
