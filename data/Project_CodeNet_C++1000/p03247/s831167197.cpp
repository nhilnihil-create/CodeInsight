// comment
// x, y 분리해서 생각하다가 망함. 그래프 그렸으면 바로 풀었을 듯
#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
using ll = long long;
using pi = pair<int, int>;
const int INF = 0x3f3f3f3f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 1e3 + 10;

int N, Nr[MAX_N][2];
// R, U, L, D;
int cx[4] = {1, 0, -1, 0};
int cy[4] = {0, 1, 0, -1};
vector<int> Line;
vector<int> Ans[MAX_N];

void pushAns(int i, int x, int y, int l) {
	if(x == 0 && y == 0) return;
	int k = -1;
	if (x-y > 0 && x+y > 0) k = 0;
	else if (x-y < 0 && x+y > 0) k = 1;
	else if (x-y < 0 && x+y < 0) k = 2;
	else k = 3;
	Ans[i].push_back(k);
	pushAns(i, x-cx[k]*l, y-cy[k]*l, l>>1);
}

int main() {
	cin >> N;
	for(int i=0; i<N; i++) for(int j=0; j<2; j++) scanf("%d", &Nr[i][j]);

	int value = abs(Nr[1][0]+Nr[1][1]) % 2;
	for(int i=0; i<N; i++) {
		if(value != abs(Nr[i][0]+Nr[i][1])%2) {
			puts("-1");
			return 0;
		}
	}
	if((Nr[1][0] + Nr[1][1]) % 2 == 0) {
		Line.push_back(1);
		for(int i=0; i<N; i++) {
			int k = 0;
			Nr[i][0] -= cx[k] * 1;
			Ans[i].push_back(k);
		}
	}
	int K = 30;
	for(int k=K; k>=0; k--) Line.push_back(1<<k);
	for(int i=0; i<N; i++) {
		pushAns(i, Nr[i][0], Nr[i][1], 1<<K);
	}

	printf("%d\n", SZ(Line));
	for(int x: Line) printf("%d ", x); puts("");
	for(int i=0; i<N; i++) {
		string S="RULD";
		for(int k: Ans[i]) printf("%c", S[k]); puts("");
	}
	return 0;
}
