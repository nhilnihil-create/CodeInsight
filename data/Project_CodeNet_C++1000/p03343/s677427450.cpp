#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define fr first
#define sc second

const int INF = 1000000000;

int main(){
	int n,k,q;
	int a[2002];
	scanf("%d%d%d",&n,&k,&q);
	for(int i = 1 ; i <= n ; i ++){
		scanf("%d",&a[i]);
	}
	
	int ret = INF;
	set<int> S; S.insert(0); S.insert(n+1);
	vector<P> vec;
	for(int i = 1 ; i <= n ; i ++){
		vec.push_back(P(a[i],i));
	}
	sort(vec.begin(),vec.end());
	for(int i = 0 ; i < n ; i ++){
		P p = vec[i];
		int cnt = 0;
		int r;
		map<int,int> T;
		for(int j = i ; j < n && cnt < q ; j ++){
			P q = vec[j];
			auto itr = S.lower_bound(q.sc);
			int x = *itr;
			--itr;
			int y = *itr;
			if(x-y >= k+1+T[x]){
				T[x] ++;
				cnt ++;
				r = q.fr;
			}
		}
		if(cnt == q)ret = min( ret , r-p.fr );
		S.insert(p.sc);
	}
	cout << ret << endl;
}

