#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 1000000000;

int main(){
	int n,k,q;
	int a[2000];
	int ans = INF;
	scanf("%d%d%d",&n,&k,&q);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	for(int i=0;i<n;i++){
		vector<int> v[2000];
		int cnt = 0;
		for(int j=0;j<n;j++){
			if(a[j]<a[i]) cnt++;
			else v[cnt].push_back(a[j]);
		}
		if((int)v[cnt].size()!=0) cnt++;
		vector<int> u;
		for(int j=0;j<cnt;j++){
			sort(v[j].begin(),v[j].end());
			for(int l=0;l<=(int)v[j].size()-k;l++){
				u.push_back(v[j][l]);
			}
		}
		if(u.size()<q) continue;
		sort(u.begin(),u.end());
		ans = min(ans,u[q-1]-a[i]);
	}
	printf("%d\n",ans);
}
