#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

int main(){
	string s;cin>>s;
	string a="abc";
	do{
		string t;
		rep(i,s.size()){
			t+=a[i%3];
		}
		string x=s;
		sort(x.begin(),x.end());
		sort(t.begin(),t.end());
		if(x==t){
			puts("YES");
			return 0;
		}
	}while(next_permutation(a.begin(),a.end()));
	puts("NO");
}