#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int n , a[1<<18],ans[1<<18];

void add(pii &ans,int num){
	if(ans.first > ans.second)swap(ans.first,ans.second);
	if(num > ans.first)ans.first = num;
}

int main(){
	cin >> n;
	for (int i = 0; i < (1<<n); ++i)scanf("%d",&a[i]);
	for(int msk = 1; msk < (1 << n);++msk){

		pii tmp = make_pair(a[0],0);
		for(int j = msk ; j > 0; j = (j-1)&msk){
			add(tmp,a[j]);
		}
		ans[msk] = tmp.first+tmp.second;
	}
	for(int i = 1; i < (1<<n);++i)
		ans[i] = max(ans[i],ans[i-1]);

	for(int i = 1; i < (1<<n);++i){
		printf("%d\n", ans[i]);
	}

	return 0;
}

