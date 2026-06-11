#include<cstdio>
#include<vector>
using namespace std;
vector<int> v[200001];
char s[200002];
int num[200001][2];
int q[200001];
bool used[200001];
int main()
{
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
		num[x][s[y]-'A']++;
		num[y][s[x]-'A']++;
	}
	int k=0;
	for(int i=1;i<=n;i++){
		if(!num[i][0]||!num[i][1]){
			q[k++]=i;
			used[i]=true;
		}
	}
	for(int i=0;i<k;i++){
		for(int j:v[q[i]]){
			if(!used[j]&&!--num[j][s[q[i]]-'A']){
				q[k++]=j;
				used[j]=true;
			}
		}
	}
	puts(k==n?"No":"Yes");
}
