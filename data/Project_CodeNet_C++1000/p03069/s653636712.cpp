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
#define toupper(S) transform(S.begin(),S.end(),S.begin(),toupper)
#define tolower(S) transform(S.begin(),S.end(),S.begin(),tolower)

int main() {
	int N;
	string S;
	cin >> N >> S;
	vector<int>SA(N);
	vector<int>SB(N);
	int cnta = 0;
	int cntb = 0;
	rep(i, N) {
		if (S[i] == '.') {
			cnta++;
		}
		SA[i] = cnta;
		if (S[i] == '#') {
			cntb++;
		}
		SB[i] = cntb;
	}
	int ans = min(cnta, cntb);
	rep(i, N) {
		ans = min(ans, SB[i]+ cnta - SA[i]);
	}
	cout << ans << endl;
}
