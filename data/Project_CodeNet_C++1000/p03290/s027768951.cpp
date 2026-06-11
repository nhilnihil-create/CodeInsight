#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int d, g;
	cin>>d>>g;
	vector<int> p(d), c(d);
	for(int i = 0; i < d; i++){
		cin>>p[i]>>c[i];
	}
	int ans = 1e9;
	for(int mask = 0; mask < (1<<d); mask++){
		int sum = 0, tot = 0;
		vector<int> vec;
		for(int i = 0; i < d; i++){
			if(mask&(1<<i)){
				sum += 100*(i + 1)*p[i] + c[i];
				tot += p[i];
			}else{
				for(int j = 0; j < p[i]; j++){
					vec.push_back(100*(i + 1));
				}
			}
		}
		while(sum < g){
			sum += vec.back(); vec.pop_back();
			tot++;
		}
		ans = min(ans, tot);
	}
	cout<<ans<<endl;

	return 0;
}