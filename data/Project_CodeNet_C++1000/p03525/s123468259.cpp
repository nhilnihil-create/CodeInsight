#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	vector<int> cnt(13, 0);
	cnt[0]++;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		cnt[a]++;
	}

	bool flg=false;
	if(cnt[0]>=2 || cnt[12]>=2) flg=true;
	for(int i=1; i<12; i++){
		if(cnt[i]>=3) flg=true;
	}
	if(flg){
		cout << 0 << endl;
		return 0;
	}

	int ans=0;
	for(int i=0; i<(1<<11); i++){
		vector<int> v;
		v.push_back(0);
		if(cnt[12]==1){
			v.push_back(12);
		}

		for(int j=1; j<12; j++){
			if(cnt[j]==0) continue;
			if(cnt[j]==2){
				v.push_back(j);
				v.push_back(-j);
			}else{
				if((i>>(j-1))%2==0) v.push_back(-j);
				else v.push_back(j);
			}
		}
		sort(v.begin(), v.end());

		int m=99;
		for(int j=0; j<v.size()-1; j++){
			for(int k=j+1; k<v.size(); k++){
				if(v[j]>0 || v[k]<0){
					m=min(m, v[k]-v[j]);
				}else{
					m=min(m, min(v[k]-v[j], 24-(v[k]-v[j])));
				}
			}
		}
		ans=max(ans, m);
	}
	cout << ans << endl;
	return 0;
}