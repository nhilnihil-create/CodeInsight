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
	unordered_map<int, int> cnt;
  	int val;
  	for(int i = 0; i < 6; i++) {
    	cin >> val;
      	cnt[val] += 1;
    }
  	int freq_2 = 0;
  	for(auto p: cnt) {
    	if (p.second == 2)
          freq_2 += 1;
    }
  	if (freq_2 == 2 && cnt.size() == 4)
    	cout << "YES" << endl;
  	else
     	cout << "NO" << endl;
    return 0;
}

