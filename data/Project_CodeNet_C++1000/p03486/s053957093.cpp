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

inline int ctoi(char c) {
	if ('a' <= c && c <= 'z') {
		return c - 'a';
	}
	else {
		return -1;
	}
}
inline char itoc(int i) {
	char c;
	c = 'a' + i;
	return c;
}
int main() {
    string s, t; cin >> s >> t;
    vi stable(26), ttable(26);

    for (int i = 0; i < s.size(); i++) {
        stable[ctoi(s[i])]++;
    }
	for (int j = 0; j < t.size(); j++) {
		ttable[ctoi(t[j])]++;
	}
	string strongS, weakT;

	for (int p = 0; p < 26; p++) {
		for (int t = 0; t < stable[p]; t++) {
			strongS += itoc(p);
		}
	}

	for (int q = 25; q >= 0; q--) {
		for (int t = 0; t < ttable[q]; t++) {
			weakT += itoc(q);
		}
	}

	if (strongS < weakT) {
		pYes;
	}
	else {
		pNo;
	}
}