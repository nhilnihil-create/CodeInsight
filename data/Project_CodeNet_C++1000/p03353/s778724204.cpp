#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
using namespace std;
typedef  long long int lint;
typedef pair<int, int> IP;
typedef pair<lint, lint> LLP;
typedef pair<char, char>CP;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define llower(v,hoge) *lower_bound(v.begin(), v.end(), hoge)
#define lupper(v,hoge) *upper_bound(v.begin(), v.end(), hoge)


int main() {
	string S;
	int K;
	cin >> S >> K;
	vector<string>V;
	int N = S.size();
	rep(i, N) {
		V.push_back(S.substr(i, 1));
	}
	rep(i, N - 1) {
		V.push_back(S.substr(i, 2));
	}
	rep(i, N - 2) {
		V.push_back(S.substr(i, 3));
	}
	rep(i, N - 3) {
		V.push_back(S.substr(i, 4));
	}
	rep(i, N - 4) {
		V.push_back(S.substr(i, 5));
	}
	sort(V); 
	V.push_back("zzzzzzzzzzz");
	int cnt = 0;
	if (V.size() == 1) {
		cout << V[0] << endl;
		return 0;
	}
	rep(i, V.size()-1) {
		if (V[i] != V[i + 1]) {
			cnt++;
		}
		if (cnt == K) {
			cout << V[i] << endl;
			return 0;
		}
	}
	
}
