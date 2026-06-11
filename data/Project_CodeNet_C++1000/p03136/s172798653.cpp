#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N; cin >> N;

  vector<int> v(N);
  for(int i = 0; i < N; i++){
    cin >> v[i];
  }

  bool flg = true;
  for(int i = 0; i < N; i++){
    int sum = 0;
    for(int j = 0; j < N; j++){
      if(i == j) continue;

      sum += v[j];
    }
    if(v[i] >= sum){
      flg = false;
      break;
    }
    if(!flg) break;
  }
  cout << (flg ? "Yes" : "No") << endl;
  
}
