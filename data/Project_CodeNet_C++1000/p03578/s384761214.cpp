#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int>freq1, freq2;

typedef pair<int,int>pii;

void init(){
	freq1.clear();
	freq2.clear();
}

int main() {
	// your code goes here
	int n,m, val;
	while(scanf("%d",&n)==1){
		init();
		for(int i=0;i<n;i++){
			scanf("%d",&val);
			freq1[val]++;
		}
		
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf("%d",&val);
			freq2[val]++;
		}
		
		bool can = true;
		for(pii p : freq2){
			int val = p.first, cnt2 = p.second;
			int cnt1 = freq1[val];
			if(cnt1 < cnt2){
				can = false; break;
			}
		}
		
		printf("%s\n", can ? "YES" : "NO");
	}
	
	return 0;
}