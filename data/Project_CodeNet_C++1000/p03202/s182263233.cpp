#include <cstdio>
#include <stack>
#include <algorithm>
#define N 200005
#define pi pair<int,int>
#define fi first
#define se second

using namespace std;

int n;
int a[N];

bool check(int);

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	int l = 1, r = 1e9, res;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)) res = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", res);
	return 0;
}

bool check(int x){
	stack<pi> st;
	for(int i = 2; i <= n; ++i)
		if(a[i - 1] >= a[i]){
			if(x == 1) return false;
			while(!st.empty() && st.top().fi > a[i]) st.pop();
			if(!st.empty() && st.top().fi == a[i]) ++st.top().se;
			else st.push(make_pair(a[i], 1));
			if(st.top().se == x){
				int las = st.top().fi; st.pop(); bool flag = false;
				while(!st.empty() && st.top().fi == las - 1){
					++st.top().se;
					if(st.top().se == x) 
						las = st.top().fi, st.pop();
					else{
						flag = true; break;
					}
				}
				if(las == 1 && !flag) return false;
				if(!flag) st.push(make_pair(las - 1, 1));
			}
		}
	return true;
}