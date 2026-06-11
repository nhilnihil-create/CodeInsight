#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <limits>
#include <list>
#include <cassert>
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
#define pno cout << "no" << endl
#define pyes cout << "yes" << endl
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
#define pNO cout << "NO" << endl
#define pYES cout << "YES" << endl
#define endl "\n"
#define pi 3.14159265358979
using namespace std;
using ll = long long;

class LargeNumber {
private:
	bool is_prime[1000 + 13];// Up to 1e6 + 13
	vector<long long> Prime_table;
public:
	vector<long long> Eratosthenes(const long long N = 1007) { // return primes up to N
		for (int i = 0; i <= N; i++)
		{
			is_prime[i] = true;
		}
		for (int i = 2; i <= N; i++)
		{
			if (is_prime[i])
			{
				for (int j = 2 * i; j <= N; j += i)
				{
					is_prime[j] = false;
				}
				Prime_table.emplace_back(i);
			}
		}
		return Prime_table;
	}

	template<typename T>
	map<T, T> Factorization(T N) const {
		map<T, T> mp;
		if (N == 1) {
			return mp;
		}

		for (int i = 0; i < Prime_table.size(); i++) {
			while (N % Prime_table[i] == 0) {
				mp[Prime_table[i]]++;
				N /= Prime_table[i];
			}
		}

		if (N > 1) mp[N]++;

		return mp;
	}


	bool isPrime(long long x) {
		if (x == 0 || x == 1) {
			return false;
		}
		return is_prime[x];
	}
};

int main() {
	int N; cin >> N;
	LargeNumber lg; lg.Eratosthenes();
	vector<int> prime_cnt(101);
	for (int i = 1; i <= N; i++) {
		map<int, int> mp = lg.Factorization(i);
		for (const auto& obj : mp) {
			prime_cnt[obj.first] += obj.second;
		}
	}
	int c2 = 0, c4 = 0, c14 = 0, c24 = 0, c74 = 0;
	for (int i = 0; i < 101; i++) {
		int c = prime_cnt[i];
		if (c > 1) c2++;
		if (c > 3) c4++;
		if (c > 13) c14++;
		if (c > 23) c24++;
		if (c > 73) c74++;
	}
	ll ans = 0;
	ans += c74;
	ans += c24 * (c2 - 1);
	ans += c14 * (c4 - 1);
	ans += (c2-2) * ((c4) * (c4 - 1) / 2);
	cout << ans << endl;
	sysp;
}