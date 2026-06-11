#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please

int getint() {
	char C;
	while (!isdigit(C = getchar()));
	int A = C - '0';
	while (isdigit(C = getchar())) A = A * 10 + C - '0';
	return A;
}

void putint(int X) {
	int keta = 0;
	char C[10];
	while (X) {
		C[keta] = '0' + X % 10;
		X /= 10;
		keta++;
	}
	for (int i = keta - 1; i >= 0; i--) putchar(C[i]);
	putchar(' ');
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	
	int N, A, B;
	N = getint();
	A = getint();
	B = getint();
	int flag = 0;
	if (A < B) {
		swap(A, B);
		flag = 1;
	}

	ll saidai = (ll)A * B;
	int saishou = A + B - 1;
	if (N < saishou || N > saidai) {
		putchar('-');
		putchar('1');
		putchar('\n');
		return 0;
	}
	
	int amari = N - B;
	vector<int> K;
	rep(i, B) {
		int kari = min(A - 1, amari);
		K.pb(kari);
		amari -= kari;
	}

	if (flag) {
		int kari = 0;
		rep(i, B) {
			rep(j, K[i] + 1) putint(K[i] - j + 1 + kari);
			kari += K[i] + 1;
		}
	}
	else {
		rep(i, B) {
			rep(j, K[i] + 1) putint(N - K[i] + j);
			N -= K[i] + 1;
		}
	}

	Would you please return 0;
}