#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
	string s, ans;
  	int k;
  	cin >> s >> k;
  	for(int i = 0; i < s.size(); i++)
      if (i % k == 0)
        ans += s[i];
  	cout << ans << endl;
    return 0;
}

