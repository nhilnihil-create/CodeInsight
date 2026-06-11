#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define fr first
#define sc second

int main(){
	static int n;
	static int a[200010],b[200010];
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i ++){
		scanf("%d",&a[i]);
	}
	for(int i = 0 ; i < n ; i ++){
		scanf("%d",&b[i]);
	}
	
	int ret = 0;
	for(int t = 0 ; t < 30 ; t ++){
		ll cnt = 0;
		for(int i = 0 ; i < n ; i ++){
			cnt += (a[i]>>t)&1;
			cnt += (b[i]>>t)&1;
		}
		cnt *= n;
		vector<int> vec;
		for(int i = 0 ; i < n ; i ++){
			vec.push_back(b[i]&((1<<t)-1));
		}
		sort(vec.begin(),vec.end());
		for(int i = 0 ; i < n ; i ++){
			cnt += vec.end()-lower_bound(vec.begin(),vec.end(),(1<<t)-(a[i]&((1<<t)-1)));
		}
		/*vec.clear();
		for(int i = 0 ; i < n ; i ++){
			vec.push_back(a[i]&((1<<t)-1));
		}
		sort(vec.begin(),vec.end());
		for(int i = 0 ; i < n ; i ++){
			cnt += vec.end()-lower_bound(vec.begin(),vec.end(),(1<<t)-(b[i]&((1<<t)-1)));
		}*/
		if(cnt%2 == 1){
			ret += (1<<t);
		}
	}
	cout << ret << endl;
}

