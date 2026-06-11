#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int x,y; cin>>x>>y;
	if(x%y==0) {cout<<-1<<endl; return 0;}
	for(int i=2; i<10; i++){
		if((x*i)%y!=0) {cout<<x*i<<endl;return 0;}
	}
}