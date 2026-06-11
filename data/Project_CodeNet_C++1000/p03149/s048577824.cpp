#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string s;
	char ch;
	while(cin>>ch) s+=ch;
	sort(s.begin(),s.end());
	cout<<(s=="1479"?"YES":"NO")<<"\n";
	return 0;
}