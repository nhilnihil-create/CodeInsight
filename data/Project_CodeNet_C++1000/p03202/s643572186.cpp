#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],ans,f=0;
map <int,int> mp;
bool check(int x){
	mp.clear();
	for (int i=2;i<=n;i++)
		if (a[i-1]>=a[i]){
			while (!mp.empty()){
				int t=mp.rbegin()->first;
				if (t>a[i]) mp.erase(t); 
				else break;
			}
			int j=a[i];
			while (mp[j]+1==x) mp.erase(j),j--;
			if (j==0) return false;
			mp[j]++;
		}
	return true;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if (a[i]<=a[i-1]) f=1;
	}
	if (!f) {puts("1");return 0;}
	int l=2,r=n;
	while (l<=r){
		int mid=(l+r)>>1;
		if (check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	printf("%d\n",ans);
}