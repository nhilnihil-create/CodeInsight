#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N; cin >> N;
  vector<int> v;
  int now_val = 0;
  int num = 0;

  for(int i = 0; i < N; i++){
    int tmp; cin >> tmp;
    if(now_val == tmp){
      num++;
    } else { 
      v.push_back(num);
      num = 1;
      now_val = tmp;
    }

    if(i == N-1 && num > 0){
      v.push_back(num);
    }
  }

  int ans = 0;
  for(int i = 0; i < v.size(); i++){
    // cerr << v[i] << endl;
    ans += v[i]/ 2;
  }
  cout << ans << endl;
}
