#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define reverse(x) reverse(x.begin(), x.end())
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long,long long>
typedef long long ll;
const int mod = 1e9+7;
using namespace std;
int n, m;

int a[55][55];
int x[] = {-1,-1,-1, 0,0,  +1,+1,+1};
int y[] = {0,+1,-1, -1,+1, 0,-1,+1};
int main(){
	int i, j;
	cin >> n >> m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			char c;
			cin >> c;
			if(c == '#'){
				a[i][j] = -1;
				for(int k=0;k<8;k++)if(a[i+x[k]][j+y[k]]>=0)a[i+x[k]][j+y[k]]++;
			}
		}
	}for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i][j]==-1)cout << '#';
			else cout << a[i][j];
		}cout << '\n';
	}
}
