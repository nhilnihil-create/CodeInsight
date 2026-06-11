#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;

  vector<string> W(N);
  set<string> S;  
  
  for (int i = 0; i < N; i++)
  {
    cin >> W.at(i);
  }
  bool ok = true;
  for (int i = 0; i < N; i++)
  {
    if (i == 0){
      S.insert(W.at(i));
      continue;
    }
    if (S.count(W.at(i))) ok = false;
    if (W.at(i - 1).at(W.at(i - 1).size() - 1) != W.at(i).at(0)) ok = false;
    S.insert(W.at(i));
  }

  if (ok){
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  
  

}