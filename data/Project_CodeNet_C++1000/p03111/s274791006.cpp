#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll MIN(ll a,ll b){
	return a<b?a:b;
}

ll a,b,c,n;
ll *arr;
ll Synthetic(ll x,ll y,ll z,ll i){
	if(i == n){
		if(x<=0||y<=0||z<=0) return 1e12;
		
		return abs(a-x)+abs(b-y)+abs(c-z);
	}

	ll op1 = Synthetic(x,y,z,i+1);
	ll op2 = Synthetic(x+arr[i],y,z,i+1)+(x>0?10:0);
	ll op3 = Synthetic(x,y+arr[i],z,i+1)+(y>0?10:0);
	ll op4 = Synthetic(x,y,z+arr[i],i+1)+(z>0?10:0);
	return MIN(op1,MIN(op2,MIN(op3,op4)));
}

int main(){
	
	cin>>n>>a>>b>>c;
	arr = new ll[n];
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<Synthetic(0,0,0,0);
	cout<<endl;
	return 0;
}