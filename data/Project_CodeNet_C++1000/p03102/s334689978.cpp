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

int n,m,c;

int B[25];
int A[25];

int main() {
        NeedForSpeed
	
	cin >> n >> m >> c;

	ll resultado = 0;
	ll resp = 0;


	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}

	for (int i = 0; i < n; i++) {
		resultado = 0;
		for (int j  = 0; j < m; j++) {
			cin >> A[j];
			resultado += B[j] * A[j];
		}

		if (resultado + c > 0) {
			resp++;
		}
	}

	cout << resp << nl;

        return 0;
}

