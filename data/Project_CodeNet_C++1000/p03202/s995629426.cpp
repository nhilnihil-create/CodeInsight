#include<cstdio>
#include<map>
int n,a[200100],ans;
bool bo=true;
std::map<int,int> mp;
bool check(int x){
	mp.clear();
	for(int i=2;i<=n;i++)
		if(a[i-1]>=a[i]){
			while(!mp.empty()){
				int maxn=mp.rbegin()->first;
				if(maxn>a[i])mp.erase(maxn); 
				else break;
			}
			int j=a[i];
			while(mp[j]+1==x)
				mp.erase(j),j--;
			if(j==0)return false;
			mp[j]++;
		}
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<=a[i-1])bo=false;		
	}
	if(bo)return puts("1"),0;
	int L=2,R=n;
	while(L<=R){
		int mid=(L+R)/2;
		if(check(mid))ans=mid,R=mid-1;
		else L=mid+1;
	}
	printf("%d\n",ans);
}