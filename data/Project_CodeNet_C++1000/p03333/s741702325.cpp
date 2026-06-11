#include<iostream>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<vector>
#include<array>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#include<cassert>
#include<functional>
#include<random>
#include<complex>
#include<bitset>
#include<chrono>
#include<boost/multiprecision/cpp_int.hpp>
#define int int64_t
#define uint uint64_t
#define REP(i, a, b) for (int64_t i = (int64_t)(a); i < (int64_t)(b); i++)
#define rep(i, a) REP(i, 0, a)
#define EACH(i, a) for (auto i: a)
#define ITR(x, a) for (auto x = a.begin(); x != a.end(); x++)
#define ALL(a) (a.begin()), (a.end())
#define HAS(a, x) (a.find(x) != a.end())
#define Min(x) *min_element(ALL(x))
#define Max(x) *max_element(ALL(x))
#define Unique(L) (L.erase(unique(ALL(L)), L.end()))
#define veccat(v1, v2) std::copy((v2).begin(),(v2).end(),std::back_inserter(v1)/*v1の後ろにv2を入れる*/)
#define intmax (std::numeric_limits<int64_t>::max() / 4)
using namespace std;
typedef boost::multiprecision::cpp_int bigint;
const double EPS = 1e-9;
const double PI = acos(-1.0);


signed main()
{
	std::cin.sync_with_stdio(false);
	std::cin.tie(0);


	int n; cin >> n;
	vector<int> L(n + 1);
	vector<int> R(n + 1);

	rep(i, n)cin >> L[i] >> R[i];

	//L,Rは区間[0,0]を含んでいる

	sort(ALL(R));
	sort(ALL(L), greater<int>());

	int ans = 0;
	int tmp = 0;
	rep(i, n + 1) {
		tmp += 2 * (L[i] - R[i]);
		ans = max(ans, tmp);
	}

	cout << ans << endl;
	
	return 0;
}