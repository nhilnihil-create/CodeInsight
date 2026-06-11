#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string s; cin>>s; int w; cin>>w;
	for (int i=0; i<s.size(); i+=w)
		cout<<s[i];
	cout<<"\n";
	return 0;
}