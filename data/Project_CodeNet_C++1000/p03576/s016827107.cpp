#include<bits/stdc++.h>
using namespace std;
const int maxn=55;

struct node{
	int x,y;
}a[maxn];

map<int,int> NowToOriX,NowToOriY;//±àºÅ->ÕæÖµ 
map<int,int> OriToNowX,OriToNowY;//ÕæÖµ->±àºÅ 

int PreSum[maxn][maxn];//Ç°×ººÍ 
int mp[maxn][maxn];//ÀëÉ¢»¯

int n,k;
long long ans,dx,dy;

bool cmpx(node xx,node yy){
	return xx.x<yy.x;
}

bool cmpy(node xx,node yy){
	return xx.y<yy.y;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	sort(a+1,a+n+1,cmpx);
	for(int i=1;i<=n;i++){
		NowToOriX[i]=a[i].x;
		OriToNowX[a[i].x]=i;
	}
	dx=a[n].x-a[1].x;
	sort(a+1,a+n+1,cmpy);
	for(int i=1;i<=n;i++){
		NowToOriY[i]=a[i].y;
		OriToNowY[a[i].y]=i;
	}
	dy=a[n].y-a[1].y;
	ans=dx*dy;
	for(int i=1;i<=n;i++){
		mp[OriToNowX[a[i].x]][OriToNowY[a[i].y]]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			PreSum[i][j]=PreSum[i-1][j]+PreSum[i][j-1]-PreSum[i-1][j-1]+mp[i][j];
		}
	}
	for(int x1=1;x1<=n;x1++){
		for(int y1=1;y1<=n;y1++){
			for(int x2=x1;x2<=n;x2++){
				for(int y2=y1;y2<=n;y2++){
					int t=PreSum[x2][y2]-PreSum[x1-1][y2]-PreSum[x2][y1-1]+PreSum[x1-1][y1-1];
					if(t>=k){
						dx=NowToOriX[x2]-NowToOriX[x1];
						dy=NowToOriY[y2]-NowToOriY[y1];
						long long area=abs(dx*dy);
						ans=min(ans,area);
					}
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
 