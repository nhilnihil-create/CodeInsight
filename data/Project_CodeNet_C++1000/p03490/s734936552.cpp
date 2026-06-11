#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define INF 1e18
#define MOD 1000000007
#define N 1000005
#define BB(V) V[V.size()-2]
#define ex(V) return printf(V),0
using namespace std;
char a[8005];
int dx[2][16005],dy[2][16005];
vector<int>vx,vy;
int main(){
	int x,y;
	scanf("%s%d%d",a,&x,&y);
	int n=strlen(a),f=0;
	int t=0;
	for(int i=0;i<n;i++){
		if(f){
			if(a[i]=='T'){
				if(f&1)vy.pb(t);
				else vx.pb(t);
				f++;
				t=0;
			}
			else t++;
		}
		else{
			if(a[i]=='F')x--;
			else f++;
		}
	}
	if(f&1)vy.pb(t);
	else vx.pb(t);
	dx[0][8000+x]=dy[0][8000+y]=1;
	for(int i=0;i<vx.size();i++){
		for(int j=0;j<=16000;j++)dx[(i+1)%2][j]=0;
		for(int j=0;j<=16000;j++){
			if(0<=j+vx[i]&&j+vx[i]<=16000)dx[(i+1)%2][j+vx[i]]|=dx[i%2][j];
			if(0<=j-vx[i]&&j-vx[i]<=16000)dx[(i+1)%2][j-vx[i]]|=dx[i%2][j];
		}
	}
	for(int i=0;i<vy.size();i++){
		for(int j=0;j<=16000;j++)dy[(i+1)%2][j]=0;
		for(int j=0;j<=16000;j++){
			if(0<=j+vy[i]&&j+vy[i]<=16000)dy[(i+1)%2][j+vy[i]]|=dy[i%2][j];
			if(0<=j-vy[i]&&j-vy[i]<=16000)dy[(i+1)%2][j-vy[i]]|=dy[i%2][j];
		}
	}
	printf("%s",dx[vx.size()%2][8000]&&dy[vy.size()%2][8000]?"Yes":"No");
}