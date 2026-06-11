#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; string s; cin>>n>>s;
	int ret=0;
	for (const char &ch : s)
		if(ch=='R') ret++;
		else ret--;
	cout<<(ret>0?"Yes":"No")<<"\n";
	return 0;
}