#include <bits/stdc++.h>
using namespace std;

vector< pair< pair<string, int>, int> >cook;

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		int p;
		cin>>p;
		cook.push_back(make_pair(make_pair(s,-p), i+1));
	}
	sort(cook.begin(), cook.end());
	for(int j=0;j<n;j++){
		cout<<cook[j].second<<endl;
	}
}