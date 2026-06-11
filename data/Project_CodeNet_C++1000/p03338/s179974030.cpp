#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;

  string X, Y;
  int max = 0;
  for (int i = 1; i < S.size(); i++)
  {
    X = S.substr(0, i);
    Y = S.substr(i);
    set<char> same_list;

    same_list.clear();
    for (auto c : X){      
      for (int j = 0; j < Y.size(); j++)
      {
        if (c == Y.at(j)){
          same_list.insert(c);
        }
      }
      if (max < same_list.size()){
        max = same_list.size();
      }
    }
  }

  cout << max << endl;
  
}