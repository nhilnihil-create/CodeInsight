#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <numeric>
#include <bitset>
#include <ext/algorithm>
#include <ext/numeric>
#define ffor(_a,_f,_t) for(int _a=(_f),__t=(_t);_a<__t;_a++)
#define all(_v) (_v).begin() , (_v).end()
#define sz size()
#define pb push_back
#define SET(__set, val) memset(__set, val, sizeof(__set))
#define FOR(__i, __n) ffor (__i, 0, __n)
typedef long long LL; using namespace std;

string S;
int N, M;

const int MAXN = 300000;

vector<int> G[MAXN];

queue<int> myremove;
int degA[MAXN], degB[MAXN];
bool added[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	cin >> S;
	
	FOR (i, MAXN)
		G[i].clear();
	SET(degA, 0);
	SET(degB, 0);
	
	int a, b;
	FOR (i, M) {
		cin >> a >> b;
		a--;
		b--;
		G[a].pb(b);
		if (S[b] == 'A')
			degA[a]++;
		else
			degB[a]++;

		
		G[b].pb(a);
		if (S[a] == 'A')
			degA[b]++;
		else
			degB[b]++;
	}

	SET(added, 0);
	while (!myremove.empty())
		myremove.pop();
		
	FOR (i, N)
		if (degA[i] == 0 || degB[i] == 0) {
			added[i] = true;
			myremove.push(i);
		}
		
	int removed = 0;
	while (!myremove.empty()) {
		removed++;
		int v = myremove.front();
		myremove.pop();
		FOR (i, G[v].sz) {
			int w = G[v][i];
			if (added[w])
				continue;
			if (S[v] == 'A')
				degA[w]--;
			else
				degB[w]--;
			if (degA[w] == 0 || degB[w] == 0) {
				myremove.push(w);
				added[w] = true;
			}
		}
	}
	if (removed == N)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	return 0;
}