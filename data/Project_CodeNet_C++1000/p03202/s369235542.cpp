#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int N = 2e5 + 10;

int n , res , maxn;
int A[N];

map<int,int> exi;
int check(int mid){
	exi.clear();	
	for (int i = 2;i <= n;i++){
		if (A[i] > A[i-1]){
		
		}else{
			if (!mid) return 0;
			int p = A[i];
			while (p && exi[p] == mid) {
				p--;
			}
			if (!p) return false;
			exi[p]++;
			
			auto it = exi.upper_bound(p);
			while(it != exi.end()) it = exi.erase(it);
		}
	}
	return true;
}

int main(){
	scanf("%d",&n);
	for (int i = 1;i <= n;i++){
		scanf("%d",A + i);
		maxn = max(maxn , A[i]);
	}
	
	int L = 0 , R = n , res = n;
	while (L <= R){
		int mid = L + R >> 1;
		if (check(mid)){
			res = mid + 1;
			R = mid - 1;
		}else{
			L = mid + 1;
		}
	}
	
	cout<<res<<endl;
	return 0;
}