///A drunk man will find his way home, but a drunk bird may get lost forever...
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair <int, int> pii;
#define pb push_back
#define f first
#define s second
#define sz(x) (int)x.size()
char a[305][305], b[305][305];
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	int n, ans = 0;
	bool bu;
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	for(int k = 0; k < n; k++){
		bu = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				b[i][j] = a[i][(j + k) % n];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(b[i][j] != b[j][i])
					bu = 1;
		if(!bu){
//			cout << k << endl;
			ans++;
		}
	}
	cout << n * ans << endl;
	return 0;
}
