#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string s,f; cin>>s>>f;
	reverse(f.begin(),f.end());
	cout<<(s==f?"YES":"NO")<<endl;
}