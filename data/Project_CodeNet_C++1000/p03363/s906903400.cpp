#include <bits/stdc++.h>
using namespace std;

long long N,pre[200010],tmp;
map<long long,long long> bingung;

int main(){
	cin>>N;
	pre[0]=0;
	bingung[0]=1;
	long long total=0;
	for(long long i=0; i<N; i++){
		cin>>tmp;
		pre[i+1]=pre[i]+tmp;
		if(bingung[pre[i+1]]!=0){
			total+=bingung[pre[i+1]];
		}
		bingung[pre[i+1]]++;
	}
	cout<<total<<'\n';
}