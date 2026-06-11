#include <bits/stdc++.h>
#define mem(i,j) memset(i,j,sizeof(i))
#define pl (p<<1)
#define pr (p<<1)|1
#define int long long
using namespace std;
inline int read(){
	char ch=' ';int res=0,f=1;
	while(!isdigit(ch)){ch=getchar();if(ch=='-')f=-1;}
	while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
	return res*f;
}
int _min(int x,int y){return x<y?x:y;}
int _max(int x,int y){return x>y?x:y;}
const int N=1e6+5;
int k,vis[N];
struct node{
	int x,ans;
};
#undef int
int main() {
	/*freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);*/
	k=read();
	deque<node>q;
	q.push_front({1,1});
	while(!q.empty()){
		node kk=q.front();
		q.pop_front();
		if(vis[kk.x])continue;
		vis[kk.x]=1;
		if(!kk.x){
			printf("%lld\n",kk.ans);
			return 0;
		}
		q.push_front({(kk.x*10)%k,kk.ans});
		q.push_back({(kk.x+1)%k,kk.ans+1});
	}
	return 0;
}