#include<bits/stdc++.h>

using namespace std;

int main(){

  int n; cin >> n;

  string s = to_string(n);

  int h = 0;

  int m = s.size();

  for(int i = 0; i < m; i++){

    int t = s[i] - '0';

    h += t;

  }

  string ans;

  if(n % h == 0){ans = "Yes";}

  else ans = "No";

  cout << ans << endl;

}

