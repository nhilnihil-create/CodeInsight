#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string s; cin>>s;
	int ret=0;
	for (const char &ch: s)
		if(ch=='x')
			ret++;
	cout<<(ret>=8?"NO":"YES")<<"\n";
	return 0;
}