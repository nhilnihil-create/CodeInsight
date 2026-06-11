#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	string a,b,c; cin>>a>>b>>c;
	int ret=0;
	for (int i=0; i<n; i++) {
		set<char> st={a[i],b[i],c[i]};
		ret+=st.size()-1;
	}
	cout<<ret<<"\n";
	return 0;
}