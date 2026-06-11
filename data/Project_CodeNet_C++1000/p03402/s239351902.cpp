#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define all(c) c.begin(), c.end()
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int a,b;
	cin >> a >> b;
	const int N = 100;
	int g[N][N];
	--a;--b;
	for(int i = 0;i < 50;++i){
		for(int j = 0;j < 100; ++j){
			g[i][j] = 0;
		}
	}
	for(int i = 50;i < 100;++i){
		for(int j = 0;j < 100; ++j){
			g[i][j] = 1;
		}
	}
	for(int i = 0;i < 50; i += 2){
		for(int j = 0;j < 100; j+=2){
			if(a){
				--a;
				g[i][j]^=1;
			}
		}
	}
	for(int i = 51;i < 100; i += 2){
		for(int j = 0;j < 100; j+=2){
			if(b){
				--b;
				g[i][j]^=1;
			}
		}
	}
	cout << N << ' ' << N << '\n';
	for(int i = 0;i < N; ++i){
		for(int j = 0;j < N; ++j)
			cout << (g[i][j]?'.':'#');
		cout << '\n';
	}
}
