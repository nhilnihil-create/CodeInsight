#include <bits/stdc++.h>
using namespace std;

const long long MOD=1000000007;
long long N,sum[27]; string s;

int main(){
	cin>>N>>s;
	for(int i=0; i<N; i++){
		sum[s[i]-'a']++;
	}
	long long total=1;
	for(int i=0; i<26; i++){
		total*=(sum[i]+1)%MOD;
		total=total%MOD;
	}
	cout<<total-1<<'\n';
}