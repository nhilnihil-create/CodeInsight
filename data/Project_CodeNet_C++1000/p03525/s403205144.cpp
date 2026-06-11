#include <bits/stdc++.h>
using namespace std;
int cnt[13]={};
int dif;
int n;
vector<int>v;
int rec(int x){
	int flag = 1;
	for(int i = 0; i < 13; i++)if(cnt[i] >= 1)flag = 0;
	if(x > 24)return 0;
	if(flag){
		return 1;
	}
	int y = x+dif;
	int ret = 0;
	if(x <= 12){
		ret |= rec(x+1);
		if(cnt[x] > 0){
			cnt[x]--;
//			cout << x <<" "<<y<<endl;
			v.push_back(x);
			ret |= rec(y);
			v.pop_back();
			cnt[x]++;
		}
	}else{
		ret |= rec(x+1);
		if(cnt[24-x] > 0){
			cnt[24-x]--;
//			cout << x <<" "<<y<<endl;
			v.push_back(x);
			ret |= rec(y);
			v.pop_back();
			cnt[24-x]++;
		}
	}
	return ret;
}
int main(){
	int ans = 12;
	cin >> n;
	cnt[0]++;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		cnt[x]++;
		if(x == 0){
			ans = 0;
		}
		if(x == 12){
			if(cnt[x] > 1)ans = 0;
		}else
		if(cnt[x] > 2)ans = 0;
	}
	if(ans == 0){
		cout<<0;
		return 0;
	}
	for(int i = 12; i > 0; i--){
//		cout<<i<<endl;
		dif = i;
		if(rec(0) == 1){
			ans = i;
			break;
		}
	}
	cout << ans <<endl;
}