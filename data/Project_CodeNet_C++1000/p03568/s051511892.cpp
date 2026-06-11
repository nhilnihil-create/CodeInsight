#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main(){
    int n; 
    cin >> n;
	int a[11];
	int kotae = 1;
	int ans = 1;
	rep(i,n){
		cin >> a[i];
		ans = ans*3;
		if(a[i]%2==0){
			kotae=kotae*2;
		}
	}
	cout << ans-kotae << endl;
}
