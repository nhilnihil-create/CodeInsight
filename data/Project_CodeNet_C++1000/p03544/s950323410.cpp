#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    ll n,L[110]={};
    cin >> n;
    L[0]=2;L[1]=1;
    if(n>1){
        rep2(i,2,n+1)L[i]=L[i-1]+L[i-2];
    }
    
    cout << L[n];
    
    
	return 0;
}