#include <bits/stdc++.h>
using namespace std;

int count(const string &S){
  int res = 0;
  for(int i = 0; i + 1 < S.size(); i++){
    if(S[i] == 'A' && S[i+1] == 'B') res++;
  }
  return res;
}

int N;
vector<string> S;

long long solve(){
  long long res = 0;
  for(int i = 0; i < N; i++) res += count(S[i]);

  int a = 0, b = 0, c = 0;
  for(int i = 0; i < N; i++){
    if(S[i][0] == 'B' && S[i][S[i].size()-1] == 'A')a++;
    else if(S[i][S[i].size()-1] == 'A')b++;
    else if(S[i][0] == 'B')c++;
  // cout << S[i] << " ";
  // cout << a << " ";
  // cout << b << " ";
  // cout << c << endl;
  }



  long long add = 0;
  if(b + c == 0) add = max(0,a - 1);
  else add = a + min(b,c);
  //cout << res << endl;
  //cout << add << endl;
  res += add;
  
  return res;
}

int main(){
  cin >> N; S.resize(N);
  for(int i = 0; i < N; i++) cin >> S[i];
  cout << solve() << endl;

}




