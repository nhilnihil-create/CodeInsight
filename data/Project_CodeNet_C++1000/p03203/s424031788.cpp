#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int h,w,n;
	cin>>h>>w>>n;
	vector<int> a(h+1,w);
	for(int i=0,x,y;i<n;i++){
		cin>>x>>y;
		x--;y--;
		a[x]=min(a[x],y);
	}
	a[h]=0;
	int rb=0;
	for(int i=1;i<=h;i++){
		if(rb>=a[i]){
			cout<<i<<endl;
			return 0;
		}
		else if(rb+1!=a[i])
			rb++;
	}
}
