#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+15;

int a[N];
bool canDoit(int n,int maxi){
	if(maxi==1){
		for(int i=0;i<n-1;++i){
			if(a[i]>=a[i+1]){
				return false;
			}
		}
		return true;
	}
	stack<pair<int,int> >st;
	for(int i=0;i<n;++i){
		if(i==0){
			st.push(make_pair(a[i],1));
			continue;
		} else {
			bool big = true;
			while(!st.empty()){
				if(st.top().first>=a[i]){
					big = false;
				}
				if(st.top().first<=a[i]){
					break;
				} else {
					st.pop();
				}
			}
			if(big){
				st.push(make_pair(a[i],1));
			} else {
				int cur = a[i];
				while(!st.empty()){
					if(st.top().first <cur){
						st.push(make_pair(cur,2));
						break;
					} else {
						if(st.top().second +1 > maxi){
							st.pop();
							--cur;
						} else {
							st.top().second += 1;
							break;
						}
					}
				}
				if(st.size()==0 && cur>0){
					st.push(make_pair(cur,2));
				}
			}
			if(st.empty()){
				return false;
			}
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
	int l = 1,r = n,mid;


	while(l<r){
		mid = (l+r)/2;
		if(canDoit(n,mid)){
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