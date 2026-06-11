#include<bits/stdc++.h>
#define ts cout<<"ok"<<endl
#define oo (1e18)
#define ll long long
#define LL unsigned long long
#define hh puts("")
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
using namespace std;
bitset<4000005> bt;
int n,sum;
inline int read(){
    int ret=0,ff=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') ff=-1;ch=getchar();}
    while(isdigit(ch)){ret=(ret<<3)+(ret<<1)+(ch^48);ch=getchar();}
    return ret*ff;
}
signed main(){
	n=read();
	bt[0]=1;//bt[i]表示i能否被构造 
	for(int i=1;i<=n;i++){
		int x=read();
		bt|=bt<<x;//整体转移 
		sum+=x;
	}
	//对于一个值x能被构造,那么s-x也能被构造,所以这个序列左右对称
	//因此扫描答案从中间开始 
	for(int i=(sum+1)>>1;i<=sum;i++)
		if(bt[i]){
			printf("%d",i);
			break;
		}
    return 0;
}