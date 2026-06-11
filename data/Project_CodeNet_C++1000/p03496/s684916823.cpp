#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i = 1; i <= n; i++)
#define INF (long long)(1e18)
#define MOD (int)(1e9+7)
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
#define yn(f) (f?"Yes":"No")
#define YN(f) (f?"YES":"NO")
#define MAX 60

int a[MAX];
signed main(){
	cout<<fixed<<setprecision(7);
	bool flag = true;
	int n, m, ma = 0, A, ti = 0;
	string str;
	
	cin>>n;
	
	rep(i,n){
		cin>>A;
		if(ma <= abs(A)){
			ma = abs(A);
			ti = i;
			if(A >= 0) flag = true;
			else flag = false;
		}
	}
	
	cout<<n+n-1<<endl;
	for(int i = 1; i <= n; i++){
		cout<<ti<<" "<<i<<endl;
	}
	if(flag == true){
		for(int i = 2; i <= n; i++){
			cout<<i-1<<" "<<i<<endl;
		}
	} else {
		for(int i = n; i >= 2; i--){
			cout<<i<<" "<<i-1<<endl;
		}
	}
	return 0;
}