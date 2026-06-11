    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      string s = "0000";
      cin >> s.at(0) >> s.at(1) >> s.at(2) >> s.at(3);
      sort(s.begin(),s.end());
      if(s=="1479") cout << "YES" << endl;
      else cout << "NO" << endl;
      return 0;
    }