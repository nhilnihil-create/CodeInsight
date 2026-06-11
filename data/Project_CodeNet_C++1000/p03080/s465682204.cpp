#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

constexpr int MAXN = 100;

char s[MAXN + 2];

int main() {
	int N;
	cin >> N >> s;
	int red = 0;
	for(int i = 0; i < N; i++)
		red += s[i] == 'R';
	if(red > N - red)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
