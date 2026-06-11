#include<bits/stdc++.h>
using namespace std;
class triplet{
	public:
	int x;
	int y;
	int z;
};
int maxJoy(triplet* arr,int n,int in,int mat[][4]){
	if(n==0) return 0;
	if(n==1){
		if(in==0) return arr[0].x;
		if(in==1) return arr[0].y;
		if(in==2) return arr[0].z;
	}
	if(mat[n][in]!=-1) return mat[n][in];
	int ans=0;
	if(in==0){
		int x=maxJoy(arr+1,n-1,1,mat);
		int y=maxJoy(arr+1,n-1,2,mat);
		 ans=arr[0].x+max(x,y);
	}
	else if(in==1){
		int x=maxJoy(arr+1,n-1,0,mat);
		int y=maxJoy(arr+1,n-1,2,mat);
		ans=arr[0].y+max(x,y);
	}
	else if(in==2){
		int x=maxJoy(arr+1,n-1,0,mat);
		int y=maxJoy(arr+1,n-1,1,mat);
		ans=arr[0].z+max(x,y);
	}
	mat[n][in]=ans;
	return ans;
}
int main(){
//	int t;
//	cin>>t;
//	while(t--){
		int n;
		cin>>n;
		triplet* arr=new triplet[n];
		for(int i=0;i<n;i++){
			cin>>arr[i].x>>arr[i].y>>arr[i].z;
		}
		int mat[n+1][4];
		memset(mat,-1,sizeof(mat));
		int ans1=maxJoy(arr,n,0,mat);
		int ans2=maxJoy(arr,n,1,mat);
		int ans3=maxJoy(arr,n,2,mat);
		cout<<max(ans1,max(ans2,ans3))<<endl;
	//}
}
