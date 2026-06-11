    #include <bits/stdc++.h>
    #define F first
    #define S second
    using namespace std;
    using ll = long long;
    typedef pair<int, int> P;
    ll Mod = 1000000007;
    int main() {
      string s;
      cin >> s;
      int N = s.size();
      vector<P> ans;
      int num = 0;
      vector<int> vec;
      if (s[N-1] == '1') {
        cout << -1 << endl;
        return 0;
      }
      if (s[0] == '0') {
        cout << -1 << endl;
        return 0;
      }
      for (int i = 0; i < N-1; i++) {
        if (s[i] != s[(N-2)-i]) {
          cout << -1 << endl;
          return 0;
        }
        if ((N/2) <= i) {
          break;
        }
        if (s[i] == '1') {
          vec.push_back(i+1);
        }
      }
      for (int i = 0; i < (int)vec.size(); i++) {
        ans.emplace_back(i+1,i+2);
      }
      num = (int)vec.size() + 2;
      for (int i = 1; i < (int)vec.size(); i++) {
        int d = vec[i] - vec[i-1];
        for (int j = 0; j < d-1; j++) {
          ans.emplace_back(i+1,num);
          num++;
        }
      }
      for (num; num <= N; num++) {
        ans.emplace_back((int)vec.size()+1,num);
      }
     
      for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i].F << " " << ans[i].S << endl;
      }
      return 0;
    }