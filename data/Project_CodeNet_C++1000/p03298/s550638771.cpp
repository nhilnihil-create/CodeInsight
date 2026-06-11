#include<iostream>
#include<cstdio> 
#include<map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 40;
const int magic = 12311;



int n ;;
bool col[maxn];
char str[maxn];
ull pow[maxn], a[maxn] ;
ll ans;


map<ull,int> mid;

void calc(){
	ull x = 0,y = 0;
	int p = n,q = 1;
	for(int i = n * 2;i > n;i--){
		if(col[i]){
			y += a[i] * pow[q],q++;	
		} else {
			x += a[i] * pow[p],p--;
		}
	}
	ans += mid[y - x];
}

void check(){
	ull x = 0,y = 0;
	int p = 1,q = n;
	for(int i = 1;i <= n;i++){
		if(!col[i]) {
			x += a[i] * pow[p],p++; 
		}	else {
			y += a[i] * pow[q],q--;
		}
	}
	mid[x - y]++;
}

void dfs1(int x){ 
	if(x > n) {
		check();
		return ;
	}
	col[x] = 0;
	dfs1(x + 1);
	col[x] = 1;
	dfs1(x + 1);
}

void dfs2(int x){
	if(x > n * 2){
		calc();
		return ;
	}
	col[x] = 0;
	dfs2(x + 1);
	col[x] = 1;
	dfs2(x + 1);
}

int main(){
	scanf("%d%s",&n,str + 1);
	for(int i = 1;i <= n * 2;i++) a[i] = str[i] - 'a' + 1;
	pow[0] = 1;
	for(int i = 1;i <= n * 2;i++) pow[i] = pow[i - 1] * magic;
	dfs1(1);
	dfs2(n + 1);
	return !printf("%lld\n",ans);
}
