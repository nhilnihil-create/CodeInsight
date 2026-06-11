#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string s; cin>>s;
	int ret=0;
	for (char &ch : s)
		if(ch=='2') ret++;
	cout<<ret<<"\n";
	return 0;
}