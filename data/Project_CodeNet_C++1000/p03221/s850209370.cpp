#pragma GCC optimize("Ofast")
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

const long long INF_L = 1e17+7;
const long long INF_I = 1e9+7;
const long long MOD = 1e9+7;
const double EPS = 1e-8;
const double PI=acos(-1);

using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n,m;
	cin >> n >> m;
	//vector<pair<int,int>> pa(m);
	vector<pair<pair<int,int>,int>> pa(m);
	
	for(int i=0;i<m;i++){
		cin >> pa[i].first.first >> pa[i].first.second;
		pa[i].second=i;
	}
	
	sort(pa.begin(),pa.end());
	
	vector<string> ans(m,"");
	int cnt=1;
	for(int i=0;i<m;i++){
		if(pa[i].first.first==pa[i+1].first.first){
			pa[i].first.second=cnt;
			cnt++;
		}else{
			pa[i].first.second=cnt;
			cnt=1;
		}
	}
	
	for(int i=0;i<m;i++){
		string a=to_string(pa[i].first.first);
		string b=to_string(pa[i].first.second);
		for(int j=0;j<6-a.size();j++){
			ans[pa[i].second]+='0';
		}
		ans[pa[i].second]+=a;
		for(int j=0;j<6-b.size();j++){
			ans[pa[i].second]+='0';
		}
		ans[pa[i].second]+=b;
	}
	
	for(int i=0;i<m;i++){
		cout << ans[i] << endl;
	}
	
	return 0;
}
