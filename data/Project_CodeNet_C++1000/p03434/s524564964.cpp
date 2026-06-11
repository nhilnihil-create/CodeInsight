#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,pii> iii;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef priority_queue<pii, vector<pii>, greater<pii>> fila_prioridade;
typedef priority_queue<iii, vector<iii>, greater<iii>> fila_prioridade_grids;

#define nl '\n'
#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


int n;
int a[105];

int main() {
        NeedForSpeed
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n,greater<int>());

	int p1 = 0;
	int p2 = 0;

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			p1+= a[i];
		} else {
			p2 += a[i];
		}
	}

	cout << abs(p1 - p2) << nl;


        return 0;
}

