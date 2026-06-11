#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
int n;
int a[maxn];
map<int,int>m;
int ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(m[a[i]]>0) m[a[i]]--,ans++;
		else{
			int tmp=(1<<(32-__builtin_clz(a[i])));
		//	cout<<tmp<<endl;
			m[tmp-a[i]]++;
		} 
	}
	printf("%d\n",ans);
	return 0;
}