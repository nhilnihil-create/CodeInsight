#include <bits/stdc++.h>
using namespace std;

int main(){
  string S,T;
  cin >> S >> T;

  sort(S.begin(), S.end());
  sort(T.begin(), T.end(), greater<char>());

  string ans= (S < T) ? "Yes"
                      : "No";

  cout << ans << endl;
}