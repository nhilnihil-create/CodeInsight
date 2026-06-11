#include<bits/stdc++.h>
using namespace std;
#define Maxn 200000 + 5

int n,q;
char s[Maxn],t[Maxn],d[Maxn];

int Drop(int x){
	for(int i = 1;i <= q;i++){
		if (s[x] == t[i])
		   x += (d[i] == 'R') ? 1:-1;
		if (x > n) return -1;
		if (x < 1) return 1;
	}
	return 0;
}
int main(){
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
		cin >> s[i];
	for(int i = 1;i <= q;i++)
		cin >> t[i] >> d[i];
	int l = 1,r = n,la = 0,ra = n + 1;
	while(l <= r){
		int mid = (l + r) >> 1;
		if (Drop(mid) == 1)
			la = mid,l = mid + 1;
		else
			r = mid - 1;			
	}
	l = 1,r = n;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if (Drop(mid) == -1)
			ra = mid,r = mid - 1;
		else 
			l = mid + 1;
	}	
	cout << ra - la - 1 << endl;
	return 0;	
}