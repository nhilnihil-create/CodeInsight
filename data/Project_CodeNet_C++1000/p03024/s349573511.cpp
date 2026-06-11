# include <bits/stdc++.h>
# define INF 1e9
using namespace std;

int main(){

  string S;
  cin >> S;
  int k = S.size();
  int win = 15-k;
  for(int i=0; i<k; ++i){
    if(S[i] == 'o') win++;
  }
  if(win >=8) cout << "YES" << endl;
  else cout << "NO" << endl;

}