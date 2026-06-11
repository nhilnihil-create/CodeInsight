#include<bits/stdc++.h>
using namespace std;
multiset<int>s;
int main(){
	int n; scanf("%d",&n);
	for(int i=1; i<=n; ++i){
		int x; scanf("%d",&x); s.insert(x);
	}
	int ans=0;
	for(int i=1; i<=n&&!s.empty(); ++i){
		int k=*(--s.end());
		s.erase(--s.end());
		for(int j=1; j<32; ++j)
			if(s.find((1<<j)-k)!=s.end()){
				++ans; s.erase(s.find((1<<j)-k)); break;
			}
	}
	printf("%d",ans);
	return 0;
}