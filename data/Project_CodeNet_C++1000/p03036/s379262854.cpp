#include <bits/stdc++.h>
using namespace std;


int r,d,x;

int solve(int a){
	int ans;
	if(a==0) return r*x-d;
	else{
		a--;
		ans =solve(a);
	}
	return(ans);
}

int main(){
	cin>>r>>d>>x;
	for(int i=0;i<10;i++){
	    int u = solve(d);
	    x=u;
	    cout<<u<<endl;
	}
}