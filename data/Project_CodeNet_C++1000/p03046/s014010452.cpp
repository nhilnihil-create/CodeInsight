#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;
typedef unsigned long long BITMASK; typedef long long ll; typedef long double ld; typedef pair<int, int> pii; typedef pair<double, double> pdd; typedef pair<long long, long long> pll;
#define has_bit(bit_mask, x) ((bit_mask) & (1ULL << (x)))
#define turn_on_bit(bit_mask, x) (bit_mask |= (1ULL << (x)))
#define turn_off_bit(bit_mask, x) (bit_mask &= (~(1ULL << (x))))
#define smallest_on_bit(bit_mask) (__builtin_ctzint((bit_mask) & (-(bit_mask))))
#define CLOCK_START clock_t chrono_clk_beg = clock()
#define CLOCK_END clock_t chrono_clk_end = clock(); cerr << (double(chrono_clk_end - chrono_clk_beg) / CLOCKS_PER_SEC) << " sec"
#define bug(args ...) cerr << __LINE__ << ">> ", err(new istringstream(string(#args)), args), cerr << '\n'
#define decToBin(name, num) string name = bitset<8>(num).to_string();
#define binToDec(name, binary) unsigned long name = bitset<8>(binary).to_ulong();
#define radToDeg(name, radians) double name = radians * 180 / M_PI;
#define all(x) x.begin(), x.end()
#define mapfind(mp, x) (mp.find(x) != mp.end())
#define arrfind(arr, x) (find(all(arr), x) != arr.end())
#define removeDuplicates(vec) sort(vec.begin(), vec.end()); vec.erase(unique(vec.begin(), vec.end()), vec.end())
#define printMat(mat) for (auto &x : mat) { for (auto &y : x) { if (y < INF) cout << setw(7) << y; else cout << setw(7) << "-"; } cout << '\n'; }
#define fillMat(mat, n, m, x) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) mat[i][j] = x;
#define printArr(arr) for (auto &x : arr) cout << x << " "; cout << '\n';
#define arrReplace(arr, from, to) for (auto &x : arr) if (x == from) x = to;
#define INF (1LL<<30)
#define INF32 (1LL<<62)
#define F first
#define S second
#define M_PI 3.14159265358979323846
inline int ceil(int a, int b) { return (a+b-1)/b; }
void err(istringstream *iss) {} template<typename T, typename ... Args> void err(istringstream *iss, const T &_val, const Args & ... args) { string _name; *iss >> _name; if (_name.back()==',') _name.pop_back(); cerr << _name << " = " << _val << "; ", err(iss, args ...); }
int str_replace(string& str, const string& from, const string& to, int limit = -1) { if(from.empty()) return 0; size_t start_pos = 0; int cnt = 0; while((start_pos = str.find(from, start_pos)) != std::string::npos) { str.replace(start_pos, from.length(), to); start_pos += to.length(); cnt++; if (cnt == limit) break; } return cnt; }
#define MOD 1000000007
#define int ll

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m, k; cin >> m >> k;
	if (m == 1)
	{
		if (k == 0) cout << "0 0 1 1\n";
		else cout << "-1\n";
		return 0;
	}
	int x = (1<<m)-1;
	if (k > x) { cout << "-1\n"; return 0; }
	for (int i = 0; i <= x; ++i)
		if (i^k) cout << i << " ";
	cout << k << " ";
	for (int i = x; i >= 0; --i)
		if (i^k) cout << i << " ";
	cout << k << " ";
	return 0;
}