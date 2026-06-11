#include <bits/stdc++.h>
using namespace std;

long long N,M; string s,t; map<long long,long long> aku_nyerah;

long long fpb(long long a, long long b){
	if(b==0){
		return a;
	}else{
		return fpb(b,a%b);
	}
}

int main(){
	cin>>N>>M>>s>>t;
	long long len=N*M/fpb(N,M),fac=fpb(N,M); bool pos=true;
	for(long long i=0; i<N; i++){
		aku_nyerah[i*len/N]=s[i]-'a';
	}
	for(long long i=0; i<M; i++){
		if(aku_nyerah.count(i*len/M)&&aku_nyerah[i*len/M]!=(t[i]-'a'))pos=false;
	}
	if(pos){
		cout<<len<<'\n';
	}else{
		cout<<-1<<'\n';
	}
}