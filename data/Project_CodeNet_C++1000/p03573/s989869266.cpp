#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int a,b,c; cin>>a>>b>>c;
	set<int> st;
	st.insert(a);
	if(st.count(b)) cout<<c<<endl;
	else if(st.count(c)) cout<<b<<endl;
  else cout<<a<<endl;
}