#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
inline void err(){
	cout<< -1<<endl;
	exit(0);
}
inline void add_edge(int u,int v){
	cout<<u<<" "<<v<<endl;
}
int main()
{

	ios_base:: sync_with_stdio(false); cin.tie(0);
	string s; cin>>s;
	int n=s.length();
	s="0"+s;

	if(s[1]=='0') {
		err();
	}
	//cout<<s<<endl;
	for(int i=1; i<=n; i++) {
		if(s[i]!=s[n-i]) {
			//	cout<<s[i]<<" "<<s[n-i]<<endl;
			//cout<<i<<" "<<n-i<<endl;
			err();
		}
	}
	int root=1;
	int last=2;
	s[n]='1';
	for(int i=2; i<=n; i++) {
		if(s[i]=='1') {
			add_edge(i,root);
			while(last!=i) {

				add_edge(last,i);
				last++;
			}
			last++;
			root=i;
		}
	}
	//add_edge(root,last);


	return 0;
}
