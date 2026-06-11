#include <bits/stdc++.h>                                                                                                                                                                                      //YaLoh

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9;
const ll INF = 1e18;
int n, a[N];
bool check(int k){
	stack< pii > st;
	st.push({1, 1});
	for(int i = 1; i < n; i++){
		if(a[i] > a[i - 1])
			continue;
		while(!st.empty() && st.top().f > a[i])
			st.pop();	
		int last = a[i];
		while(!st.empty()){
			auto it = st.top();
			if(it.f < last && k > 1){
				st.push({last, 2});
				break;
			}
			if(it.s == k){
				last = it.f - 1;
				st.pop();
				continue;
			}
			st.pop();
			it.s++;
			st.push(it);
			break;
		}
		if(st.empty())
			return 0;
	}
	return 1;
}
int main(){
	scanf("%d", &n);         
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int l = 1, r = n;
	while(l <= r){
		int m = (l + r) / 2;
		if(check(m))
			r = m - 1;
		else
			l = m + 1;
	}
	printf("%d", l);
	return 0;
}
