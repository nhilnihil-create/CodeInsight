#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  // ....#####という形にする
  // i番目まで., i+1から#
  // i番目までの.の個数
  // i番目までの#の個数を数えておく


  int N; cin >> N;
  string S; cin >> S;
  vector<int> a(N,0), b(N,0);
  for(int i = 0; i < N; i++){
    if(S[i] == '.'){
      a[i]++;
    } else { 
      b[i]++;
    }
    if(i > 0){
      a[i] += a[i-1];
      b[i] += b[i-1];
    }
  }

  int a_num = a[N-1];
  int b_num = b[N-1];
  // cerr << a_num << " " << b_num << endl;

  int min_num = a_num;
  for(int i = 0; i < N; i++){
    // 0   - i をすべて.に変えて、
    // i+1 - N をすべて#にかえる
    int tmp = 0;
    tmp += b[i];
    tmp += a_num - a[i];
    min_num = min(tmp, min_num);
  }
  cout << min_num << endl;
}
