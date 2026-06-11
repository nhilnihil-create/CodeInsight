#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string s; cin>>s;
	if(s.size()==3)
		reverse(s.begin(),s.end());
	cout<<s<<"\n";
	return 0;
}