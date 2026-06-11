#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
const int maxn = 1e5 + 5;
const int inf = 1000000000;
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338; // double PI = 4*atan(1);

	 

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio
	//ifstream cin (".in");
	//ofstream cout (".out");
	int N,M,C;
    cin >> N >> M >> C;
    vector<int>B(M);
    for(int i = 0; i < M; i++) {
        cin >> B[i];
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int res = 0;
        for(int j = 0; j < M; j++) {
            int A;
            cin >> A;
            res += A*B[j];
        }
        res += C;
        if(res > 0) {
            ans++;
        }
    }
    cout << ans << endl;
 }


