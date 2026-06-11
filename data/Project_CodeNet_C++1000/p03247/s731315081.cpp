#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
#define LL long long
const int N = 1010;
const char opt[] = {'L','R','D','U'};
pair<LL,LL>point[N];
int n;
string ans[N];
LL d[33];
inline int check(LL x,LL y,char opt,LL d){
	switch(opt){
		case 'R':
			return abs(x - d) + abs(y) <= d - 1;
		case 'L':
			return abs(x + d) + abs(y) <= d - 1;
		case 'U':
			return abs(x) + abs(y - d) <= d - 1;
		case 'D':
			return abs(x) + abs(y + d) <= d - 1; 
	}
}
inline void nxt(int& x,int& y,char opt,int d){
	switch(opt){
		case 'R':
			x -= d;break;
		case 'L':
			x += d;break;
		case 'U':
			y -= d;break;
		case 'D':
			y += d;break;
	}
}
int nowx,nowy;
int main(){
	scanf("%d",&n);
	int equal = 1;
	d[1] = 1;
	for(int i = 2;i <= 31;++i)d[i] = d[i - 1] << 1;
	for(int i = 1;i <= n;++i){
		scanf("%lld%lld",&point[i].first,&point[i].second);
		equal &= ((point[i].first + point[i].second) & 1) == ((point[1].first + point[1].second) & 1);
	}
	if(!equal)
		return puts("-1"),0;
	int k = 31;
	if((point[1].first + point[1].second) % 2 == 0){
		k++;
		d[32] = 1; 
		for(int i = 1;i <= n;++i)ans[i] = 'D' + ans[i],point[i].second++;
	}
	printf("%d\n",k);
	for(int i = 1;i <= k;++i)printf("%lld ",d[i]);
	puts("");
	for(int i = 1;i <= n;++i){
		nowx = point[i].first,nowy = point[i].second;
		for(int k = 31;k;--k){
			for(int j = 0;j < 4;++j)
			if(check(nowx,nowy,opt[j],d[k])){
				ans[i] = opt[j] + ans[i];
				nxt(nowx,nowy,opt[j],d[k]);
//				cout << ans[i] << endl;
				break;
			}
		}
		cout << ans[i] << '\n';
	}
	return 0;
}