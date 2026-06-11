#include<bits/stdc++.h>
using namespace std;

#define ll long long
//~ #define endl '\n'

void solve(){
	int x, y; cin>>x>>y;
	if(x == y){
		cout<<-1<<endl;
	}else if(x > y){
		if(x%y == 0){
			cout<<-1<<endl;
		}else{
			cout<<x<<endl;
		}
	}else{
		cout<<x<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int ty = 1; //cin>>ty;
	while(ty--){
		solve();
	}
	return 0;
}
