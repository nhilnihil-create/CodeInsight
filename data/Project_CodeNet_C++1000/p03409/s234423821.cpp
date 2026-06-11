#include<bits/stdc++.h>

using namespace std;

int n, ans;
vector< pair<int, int> > red, blue;

bool comp(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

int main(){
	cin >> n;
	red.resize(n); blue.resize(n);
	for(int i = 0; i < n; ++i) cin >> red[i].first >> red[i].second;
	for(int i = 0; i < n; ++i) cin >> blue[i].first >> blue[i].second;

	sort(blue.begin(), blue.end());
	sort(red.begin(), red.end(), comp);
	reverse(red.begin(), red.end());

	while(blue.size() > 0){
		auto bml = blue.begin();
		for(auto itr = red.begin(); itr != red.end(); itr++){
			if(itr->first < bml->first && itr->second < bml->second){
				ans++;
				red.erase(itr);
				break;
			}
		}
		blue.erase(bml);
	}

	cout << ans << endl;
}