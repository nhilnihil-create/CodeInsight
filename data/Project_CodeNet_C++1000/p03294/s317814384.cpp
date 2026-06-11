#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    int n , t = 0;
    cin >> n;
	int a;
	for(int i = 0; i < n; i++){ 
        cin >> a;
        t+=a;
    }
	t-=n;
    cout << t << endl;
}
