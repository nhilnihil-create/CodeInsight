#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<bitset>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
using namespace std;
using ll = long long;
template<typename T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1LL << 60;
#define all(x) (x).begin(),(x).end()
#define puts(x) cout << x << endl
#define rep(i,m,n) for(ll i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(ll i = m;i >= n;--i)

int main() {
	int N;
	cin >> N;
	vector<string>S(N);
	for (int i = 0; i < N; i++)cin >> S[i];
	
	int ans = 0;
	for (int b = 0; b < N; b++) {
		int cnt = 0;
		vector<vector<char>>temp(N,vector<char>(N));
		for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)temp[i][j] = S[i][(j+b)%N];
		for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)if (temp[i][j] == temp[j][i])cnt++;
		if (cnt == N * N)ans += N;
	}
	puts(ans);

	return 0;
}