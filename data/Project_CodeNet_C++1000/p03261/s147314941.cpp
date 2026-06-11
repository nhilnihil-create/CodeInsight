#include <bits/stdc++.h>
using namespace std;


int main() {
    int N;
    int s;
    cin >> N;
    vector<string> W(N); cin >> W.at(0);
    s = W.at(0).size();
    for(int i=0;i<N-1;++i){
      cin >> W.at(i+1);
      if(W.at(i).at(s-1) != W.at(i+1).at(0)){
        cout << "No" << endl;
        return 0;
      }
      for(int j=0;j<i+1;++j){
        if(W.at(i+1) == W.at(j)){
          cout << "No" << endl;
          return 0;
        }
      }
      s = W.at(i+1).size();
    }
    cout << "Yes" << endl;
    return 0;
}
