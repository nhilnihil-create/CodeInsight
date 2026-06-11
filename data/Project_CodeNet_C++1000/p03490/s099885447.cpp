#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

vector<int> v1, v2;
char s[8010];
int l, x, y;
bool d[2][18001];
int p=9000;

bool pos(vector<int>& v, int n) {
	if(v.empty()) return n==0;
	if(n+p<0 || n+p>18000) return false;
	memset(d,0,sizeof(d));
	d[1][p]=1;
	int from=1, to=0;
	for(int i=0;i<v.size();i++) {
		for(int j=-9000;j<=9000;j++) {
			d[to][j+p]=0;
			int tar=j-v[i]+p;
			if(tar>=0 && tar<=18000 && d[from][tar]) {
				d[to][j+p]=1;
			}
			tar=j+v[i]+p;
			if(tar>=0 && tar<=18000 && d[from][tar]) {
				d[to][j+p]=1;
			}
		}
		from^=1; to^=1;
	}
	return d[(v.size()-1)%2][n+p];
}

int main() {
	scanf("%s %d %d",s,&x,&y);
	l=strlen(s);
	int t=0, cur=0;
	bool fst=true;
	for(int i=0;i<=l;i++) {
		if(s[i]=='F') cur++;
		else {
			if(fst && cur>0) {
				x-=cur;
				cur=0;
				t^=1;
				fst=false;
				continue;
			}
			if(cur) {
				if(!t) v1.push_back(cur);
				else v2.push_back(cur);
			}
			cur=0; t^=1;
			fst=false;
		}
	}
	if(pos(v1,x) && pos(v2,y)) puts("Yes");
	else puts("No");
	return 0;
}