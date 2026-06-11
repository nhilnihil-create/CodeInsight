#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+15;
int a[N];

bool canDoit(int c,int n){
	if(c==1){
		for(int i=0;i<n-1;++i){
			if(a[i]>=a[i+1]){
				return false;
			}
		}
		return true;
	}
	stack<pair<int,int> > st;
	int u = 0;
	if(a[0] ==1){
		u = 1;
	}
	st.push(make_pair(1,1));
	for(int i=u;i<n;++i){		
		int t = 0;
		while(!st.empty()){
			if( st.top().first>a[i]){
				st.pop();
				t = 1;
			} else {
				break;
			}
		}
		int cur = a[i];
		while(!st.empty()){
			if( st.top().first == cur){
				t = 1;
				int sc = st.top().second + 1;
				if(sc<=c){
					st.top().second += 1;
					break;
				} else {
					st.pop();
					--cur;
				}
			} else {
				st.push(make_pair(cur,t+1));
				break;
			}
		}
		if(st.size()==0){
			return false;
		}
	}
	return true;
}
void solve(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	int l = 1,r = n, mid;

	while(l<r){
		mid = (l + r)/2;
		if(canDoit(mid,n)){
			r = mid;
		} else {
			l = mid+1;
		}
	}
	printf("%d\n",l);
}
int main(){
	//freopen("input.txt","r",stdin);
	solve();
}