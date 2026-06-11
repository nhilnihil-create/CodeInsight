#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int n;
    int a_max = 0;
    int a_min = INF;
    cin >> n;
    int a[n];
    rep(i,n){
        cin >> a[i];
        a_max = max(a_max,a[i]);
        a_min = min(a_min,a[i]);
    }
    
    cout << a_max-a_min;
    
	return 0;
}