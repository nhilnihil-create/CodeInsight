#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
	int n,t,x,y;
	int x1=0,y1=0,t1=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t>>x>>y;
		if((t-t1)-abs(x-x1)-abs(y-y1)>=0 && ((t-t1)-abs(x-x1)-abs(y-y1))%2==0){
			t1=t;
			x1=x;
			y1=y;
		}
		else{
			cout<<"No"<<endl;
			return(0);
		}
	}
	cout<<"Yes"<<endl;
    return(0);
}