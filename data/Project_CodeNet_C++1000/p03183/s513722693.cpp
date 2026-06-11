
#include <bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int> trinca;
typedef long long ll;

const int MAXW = 2*1e4 + 10;

vector<trinca> guloso;
ll dp[MAXW];
int N;

int main(){

	cin >> N;
	for(int i = 1;i<=N;i++){
		int w,s,v;
		cin >> w >> s >> v;
		guloso.push_back(make_tuple(s+w,w,v));
	}

	sort(guloso.begin(),guloso.end());

	ll best=0;
	for(trinca davez : guloso){
		int solid = get<0>(davez), w = get<1>(davez);
		ll v = get<2>(davez);
		for(int i =solid-w;i>=0;i--){

				dp[i+w] = max(dp[i+w],dp[i] + v);

				best=max(best,dp[i+w]);

		}
	}


	cout << best << endl;

	return 0;

}
