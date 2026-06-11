#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define rep(i,n) for(int i = 0; i < (n); i++)
#define INF ((long long)1e18)
#define MOD ((int)1e9+7)
#define endl "\n"

#define yn(f) ((f)?"Yes":"No")
#define YN(f) ((f)?"YES":"NO")

#define MAX 210000

int N, Q;
vector<pair<char,char> > golem;
string s;

int check(int num){
	if(num >= N) return 1;
	else if(num < 0)return -1;
	
	for(int i = 0; i < Q; i++){
		if(s[num] == golem[i].first){
			if(golem[i].second == 'R') num++;
			else num--;
		}
		// cout<<num<<" ";
		if(num >= N) return 1;
		if(num < 0) return -1;
	}
	return 0;
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	char t, d;
	
	cin>>N>>Q;
	
	cin>>s;
	
	for(int i = 0; i < Q; i++){
		cin>>t>>d;
		golem.push_back(make_pair(t,d));
	}
	
	int low = -1, high = N+1, m, ans = 0;
	
	// for(int i = 0; i < N; i++){
	//	cout<<"i = "<<i<<" "<<check(i)<<endl;
	//	 }
	
	while(low + 1 < high){
		m = (low+high)/2;
		if(check(m) == -1) low = m;
		else high = m;
	}
	ans = high;
	low = -1, high = N+1;
	
	while(low + 1 < high){
		m = (low+high)/2;
		if(check(m) != 1) low = m;
		else high = m;
	}
	//cout<<ans<<" "<<N-high<<endl;
	
	ans = N-(ans+N-high);
	
	cout<<ans<<endl;
	
	
	return 0;
}
