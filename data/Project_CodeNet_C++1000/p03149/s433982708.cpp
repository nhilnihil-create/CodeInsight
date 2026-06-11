// A - Beginning
#include <bits/stdc++.h>
using namespace std;

int main(){
	char a,b,c,d; cin>>a>>b>>c>>d;
	map<char,bool> m;
	m[a] = m[b] = m[c] = m[d] = true;
	string s ="1974";
	for(auto c:s) if(m[c]==false){ puts("NO"); return 0; }
	puts("YES");
}