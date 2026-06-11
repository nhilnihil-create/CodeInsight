#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define inf 1000000007
using namespace std;
int used[114514];
signed main(){
	int n,k;
	cin>>n>>k;
	vector< pair<int,int> > sus;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		sus.pb(mp(y,x));
	}
	sort(sus.begin(),sus.end());
	reverse(sus.begin(),sus.end());
	vector<ll> fir;
	priority_queue<ll> dup;
	ll sum=0;
	for(int i=0;i<k;i++){
		if(used[ sus[i].second ] == 0){
			used[ sus[i].second ] = 1;
			fir.push_back(sus[i].first);
			sum += sus[i].first;
		}
		else{
			dup.push(-sus[i].first);
			sum += sus[i].first;
		}
	}
	vector<ll> anss;
	anss.pb(sum+fir.size()*fir.size());
	for(int i=k;i<sus.size();i++){
		if(used[sus[i].second]==0 && !dup.empty()){
			used[sus[i].second] = 1;
			sum -= -dup.top();
			dup.pop();
			fir.push_back(-sus[i].first);
			sum+=sus[i].first;
			anss.pb(sum+fir.size()*fir.size());
		}
	}
	sort(anss.begin(),anss.end());
	cout<<anss[anss.size()-1]<<endl;
	return 0;
}