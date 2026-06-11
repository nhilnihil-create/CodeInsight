#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin() , x.end()
#define clr(x) memset(x , 0 , sizeof x);
#define sz(x) (int)x.size()
const int xx = 2e5;
const int Mod = 1e9 + 7;
const int inf = 1e18;
const int Maxn = 20010;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  if(N == 0 || N == 1){
    cout << N << '\n';
    return 0;
  }
  vector<int> evP, oddP;

  for(int i = 1; i<= 33; i+= 2){
    int x = (1ll << i);
    x = x * -1;
    oddP.push_back(x);
  }
  for(int j = 0; j <= 34; j += 2) {
    evP.push_back(1ll << j);
  }
  map<int,int> Sum;
  int M = sz(evP);
  map<int,int> Sno_E , Sno_O;
  Sum[0] = 1;
  for(int i = 1; i < (1 << M); i++) {
    int sum =0;
    for(int j = 0; j < M; j++) {
      if(i & (1 << j) ){
        sum += evP[j];
      }
    }
    Sum[sum] = 1;
    Sno_E[sum] = i;
  }
  vector<int> odsum = {0};
  int L = sz(oddP);
  for(int i = 1; i <= (1 << L); i++) {
     int sum = 0;
     for(int j = 0; j < L; j++) {
       if(i & (1 << j)) {
         sum += oddP[j];
       }
     }
     Sno_O[sum] = i;
     odsum.push_back(sum);
  }

  int seven  = -1 , sodd = -1;
  for(int i : odsum){
    int x = N - i;
    if(Sum[x]) {
      seven = Sno_E[x];
      sodd = Sno_O[i];
    }
  }
  if(seven == -1 || sodd == -1){
    cout << 0 << '\n'; return 0;
  }
  vector<char> ans(40 , '0');
  int A = 0 , B = 0;
  for(int i = 0; i < M; i++) {
    if(seven & (1 << i)){
      int x = log2(evP[i]);
      ans[x] = '1';
    }
  }
  for(int i = 0; i < L; i++) {
    if(sodd & (1 << i)) {
      int x = log2(oddP[i] * -1);
      ans[x] = '1';
    }
  }

  bool one = false;
  for(int i = 36; i>= 0; i--) {
    if(ans[i] == '1') one = true;
    if(one){
      cout << ans[i];
    }
  }
  cout << '\n';
}
