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
#include<cmath>
#include<limits>
#define ll long long
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
using namespace std;

class Arithmetics {
private:
	bool is_prime[300000 + 13];// Up to 3e5 + 1
	vector<long long> Prime_table;
public:
	vector<long long> Eratosthenes(const long long N = 300007) { // return primes up to N
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

	vector<vector<long long>> Factorization(long long N) const {
		if (N == 1) {
			return { {-1} };
		}
		vector<vector<long long>> res;
		for (int i = 0; i < Prime_table.size() && N != 1; i++) {
			if (N % Prime_table[i] == 0) {
				res.push_back({ Prime_table[i],1 });
				N /= Prime_table[i];
				while ((N %= Prime_table[i]) == 0 && N != 0) {
					int index = res.size() - 1;
					res[index][1]++;
					N /= Prime_table[i];
				}
			}
		}

		if (N > Prime_table.back()) {
			res.push_back({ N,1 });
		}
		return res;
	}

	bool isPrime(long long x) {
		if (x == 0 || x == 1) {
			return false;
		}
		return is_prime[x];
	}
};

int main() {
	Arithmetics ars;
	ars.Eratosthenes();
	int M = 100007;
	vector<int> acc(M);
	acc[1] = 0;
	for (int i = 1; 2 * i + 1 < M; i++) {
		int J = 2 * i + 1;
		bool bN = ars.isPrime(J);
		bool bN1 = ars.isPrime((J + 1) / 2);
		if (bN && bN1) {
			acc[J] = acc[J - 2] + 1;
		}
		else {
			acc[J] = acc[J - 2];
		}
	}


	int Q; cin >> Q;
	for (int t = 0; t < Q; t++) {
		int l, r; cin >> l >> r;
		int u = 0;
		if (ars.isPrime(l) == true && ars.isPrime((l+1)/2) == true) {
			u++;
		}
		cout << acc[r] - acc[l] + u << endl;
	}
}