#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int c[10][10];	//c[i][j] cost of making  i->j
vector <int> d(10,INT_MAX);		//mincost of making i->1
vector <bool> vis(10,false);	

int main(){
	int h,w,ans,k;
	cin>>h>>w;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			cin>>c[i][j];
	
	d[1]=0; 
	for(int i=0;i<10;i++){
		
		int Min = INT_MAX,Min_j;
		for(int j=0;j<10;j++){
			if(vis[j]==false && d[j]<Min){
				Min_j = j;
				Min = d[j];
			} 
		}
		vis[Min_j]=true;
		
		for(int j=0;j<10;j++){
			if(vis[j]==false && j!=Min_j)
				d[j] = min(d[j],c[j][Min_j]+d[Min_j]);
		}
	}
	
	ans=0;
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++){
			cin>>k;
			if(k!=-1)
				ans+=d[k];
			}
			
	cout<<ans<<endl;
}
