#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

int main(){
	vector<string> ans = {"KIHBR", "AKIHBR", "KIHABR", "AKIHABR", "KIHBAR", "AKIHBAR", "KIHABAR", "AKIHABAR", "KIHBRA", "AKIHBRA", "KIHABRA", "AKIHABRA", "KIHBARA", "AKIHBARA", "KIHABARA", "AKIHABARA"};
	sort( ans.begin(), ans.end() );
	string s; cin >> s;
	if( binary_search( ans.begin(), ans.end(), s ) ) cout << "YES" << endl;
	else cout << "NO" << endl;
}