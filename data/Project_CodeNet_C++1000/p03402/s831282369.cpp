#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
#define pprint(A,m,n) rep(j,0,m){print(A[j],n);}
const long mod=1e9+7;
const int size=1e5;
const long inf=1e9;
int main(){
	char grid[100][100];
	rep(i,0,100)rep(j,0,100){
		if(i<50) grid[i][j]='#';
		else grid[i][j]='.';
	}
	int A,B;cin>>A>>B; A--; B--;
	int cnt=0;
	for(int i=0;i<100;i+=2){
		for(int j=0;j<100;j+=2){
            if(cnt==A) break;
			grid[i][j]='.';
			cnt++;
		}if(cnt==A) break;
	}
	cnt=0;
	for(int i=99;i>=0;i-=2){
		for(int j=0;j<100;j+=2){
            if(cnt==B) break;
			grid[i][j]='#';
			cnt++;
		}if(cnt==B) break;
	}
    cout<<100<<" "<<100<<endl;
	rep(i,0,100){
		rep(j,0,100){
			cout<<grid[i][j];
		}cout<<endl;
	}
}