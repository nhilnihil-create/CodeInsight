#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	long long n,m;
	cin>>n>>m;
	vector<long long> card(n);
	for(int i=0;i<n;i++) cin>>card.at(i);
	sort(card.begin(),card.end());

	priority_queue<pair<long long,long long>> change;
	for(int i=0;i<m;i++){
		long long b,c;
		cin>>b>>c;
		change.push(make_pair(c,b));
	}

	long long numoftop=change.top().second;

	for(int i=0;i<n;i++){
		if(change.size()>0 && card.at(i)<change.top().first){
			card.at(i)=change.top().first;
			numoftop--;

			if(numoftop<=0){
				change.pop();
				if(change.size()>0) numoftop=change.top().second;
			}
		}
	}

	long long ans=0;

	for(auto a:card) ans+=a;

	cout<<ans<<endl;

	return 0;
}
