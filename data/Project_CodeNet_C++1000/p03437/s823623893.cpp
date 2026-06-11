#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll x,y;
	cin>>x>>y;
	if(x%y==0){
		cout<<-1<<endl;
	}else{
		cout<<x<<endl;
	}
	return 0;
}
