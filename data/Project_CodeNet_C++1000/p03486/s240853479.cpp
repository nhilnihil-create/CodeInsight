#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;

int main(){
	string s,t;
	cin>>s>>t;
	sort(all(s));
	sort(all(t));
	reverse(all(t));
	if(s.compare(t)<0) cout<<"Yes";
	else cout<<"No";
}