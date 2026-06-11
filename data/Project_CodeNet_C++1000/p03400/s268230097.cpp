#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int n,d,x;
    int sum = 0;
    int coe=0;
    cin >> n >> d >> x;
    int a[n];
    rep(i,n)cin >> a[i];
    rep(i,n){
        coe = 0;
        while(coe*a[i]+1<=d){
            sum++;
            coe++;
        }
    }
    
    cout << sum + x;
    
	return 0;
}