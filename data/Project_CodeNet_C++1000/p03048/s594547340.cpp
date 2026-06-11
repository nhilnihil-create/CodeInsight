#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false); cin.tie(0);
	cin.exceptions(cin.failbit);

	int R, G, B, N; cin >> R >> G >> B >> N;
	
	int acc = 0;
	for (int r = 0; r * R <= N; r++)
		for (int b = 0; r * R + b * B <= N; b++)
			if ((N - r * R - b * B) % G == 0)
				acc++;
	cout << acc << endl;
}
