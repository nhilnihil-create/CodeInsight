#include<iostream>
#include<vector>
using namespace std;
const int N=2e5+2;
vector<int> lis;
int ar[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,i,j,k,l,lef,rig,mid,num,now;
	cin>>n;
	bool cac=true;
	for(i=1;i<=n;i++){
		cin>>ar[i];
		if(i-1&&ar[i]<=ar[i-1]){
			cac=false;
		}
	}
	if(cac){
		cout<<1;
		return 0;
	}
	rig=n;
	lef=1;
	while(rig>lef){
		mid=(lef+rig)/2;
		//cout<<mid<<endl;
		lis.clear();
		for(i=1;i<n;i++){
			if(ar[i]<ar[i+1]){
				continue;
			}
			while(lis.size()&&lis.back()>ar[i+1]){
				lis.pop_back();
			}
			now=ar[i+1];
			while(true){		
				if(lis.size()<mid||lis[lis.size()-mid]<now){
					lis.push_back(now);
					break;
				}
				else{
					for(j=0;j<mid;j++){
						lis.pop_back();
					}
					now--;
				}
			}	
		}
		if(!lis.size()||lis[0]>0){
			rig=mid;
		}
		else{
			lef=mid+1;
		}
	}
	cout<<lef+1;
}