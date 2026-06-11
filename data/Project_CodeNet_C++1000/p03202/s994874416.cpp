#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::map<int,int>S;
std::set<int>T;
int n,A,mid;
void set(int p,int x){
	S[p]=x;
	if(x==mid){
		if(T.count(p))T.erase(p);
		if(!S.count(p-1)||S[p-1]<mid)T.insert(p-1);
	}
}
int len[200010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi();
	for(int i=1;i<=n;++i)len[i]=gi();
	bool flg=0;
	for(int i=1;i<n;++i)if(len[i]>=len[i+1])flg=1;
	if(!flg)return puts("1"),0;
	int l=1,r=n;
	while(l<r){
		mid=((l+r)>>1);
		A=len[1];
		S.clear(),T.clear();
		T.insert(0);
		bool flg=0;
		for(int i=2;i<=n;++i){
			int B=len[i];
			if(B<=A){
				while(!S.empty()&&(--S.end())->first>B)S.erase(--S.end());
				while(!T.empty()&&*--T.end()>B)T.erase(--T.end());
				if(!S.count(B)||S[B]<mid)set(B,S[B]+1);
				else{//S[B]=mid
					int p=*--T.lower_bound(B);
					if(!p){l=mid+1;flg=1;break;}
					else{
						set(p,S[p]+1);
						while(!S.empty()&&(--S.end())->first>p)S.erase(--S.end());
						while(!T.empty()&&*--T.end()>p)T.erase(--T.end());
					}
				}
			}
			A=B;
		}
		if(!flg)r=mid;
	}
	printf("%d\n",l+1);
	return 0;
}
