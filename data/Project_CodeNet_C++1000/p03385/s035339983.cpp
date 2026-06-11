#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string s; cin>>s;
	set<char> st;
	rep(i,3) st.insert(s[i]);
	cout<<(st.size()==3?"Yes":"No")<<endl;
}