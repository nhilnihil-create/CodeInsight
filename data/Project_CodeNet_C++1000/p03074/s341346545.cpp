#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
vector<pair<char,int>> run_comp(string S){
  vector<pair<char,int>> v;
  char now = S[0];
  int num = 1;
  char tmp = S[S.size()-1];
  for(int i = 1; i < S.size(); i++){
    tmp = S[i];
    if(now == tmp){
      num++;
    } else { 
      v.push_back(make_pair(now, num));
      num = 1;
      now = tmp;
    }
  }

  v.push_back(make_pair(tmp, num));

  return v;
}

int main(){
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  auto x = run_comp(S);
  
  int ans;
  if(x.size() == 1){
    if(S[0] == '0'){
      if(K>0){
        ans = N;
      } else {
        ans = 0;
      }
    } else { 
      ans = N;
    }
    cout << ans << endl;
    return 0;
  }

  bool head_flg = (S[0] == '1' ? true: false);
  bool tail_flg = (S[S.size()-1] == '1' ? true: false);

  vector<int> v;
  if(head_flg){
    //
  } else { 
    v.push_back(0);
  }
  for(auto y:x){
    v.push_back(y.second);
  }
  if(tail_flg){
    //
  } else { 
    v.push_back(0);
  }
  // vは１始まり、1終わり


  if(2*K+1 > v.size()){
    K = v.size()/2;
  }


  // -> 偶数番目を1にした時の最長長さを求める
  vector<int> w(v.size());
  w[0] = v[0];
  for(int i = 1; i < w.size(); i++){
    w[i] = w[i-1] + v[i];
  }
  // K = 1なら、012, 234, -> w[2], w[4] - w[1], ...
  // K = 2なら、01234, -> w[4], w[6] - w[1], ...

  ans = w[2*K];
  int index = 1;
  while(index + 2*K + 1 < w.size()){
    ans = max(ans, w[index + 2*K +1] - w[index]);
    index+=2;
  }
  
  cout << ans << endl;
}
