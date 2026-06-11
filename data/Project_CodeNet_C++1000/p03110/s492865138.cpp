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
    cin >> n;
    double x[n];
    string u[n];
    rep(i,n)cin >> x[i] >> u[i];
    double sum = 0;
    rep(i,n){
        if(u[i]=="JPY")sum+=x[i];
        if(u[i]=="BTC")sum+=x[i]*380000;
    }
    
    cout << sum;
    
	return 0;
}