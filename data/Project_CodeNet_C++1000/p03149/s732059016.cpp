// A - Beginning
#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,d; cin>>a>>b>>c>>d;
	map<int,int> m;
	m[a] = m[b] = m[c] = m[d] = 1;
	string s ="1974";
	for(auto c:s) if(m[c-'0']!=1){ puts("NO"); return 0; }
	puts("YES");
}