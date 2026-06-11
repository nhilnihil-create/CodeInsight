#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,a; cin >> n;
	int sum =0;
	if(n==1) cout << "Hello World" << endl;
	if(n==2){
		while(n--){
			cin >> a;
			sum += a;
		}
		cout << sum << endl;
	}
	return 0;
}
