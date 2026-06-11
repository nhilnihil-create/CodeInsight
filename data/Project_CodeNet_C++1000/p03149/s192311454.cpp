#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
#define ote(x) cout<<(x)<<endl
#define all(x) (x).begin(),(x).end()
#define rp(i,s,e) for(int i=(s);i<(e);++i)

int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	map<int,int> m;
	m[a]++;
	m[b]++;
	m[c]++;
	m[d]++;
	string s ="1974";
	for(auto c:s){
		int i = c-'0';
		if(m[i]!=1){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}
