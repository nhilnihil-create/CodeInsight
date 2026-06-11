#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
string k;
ll mx,p,i;
int main(){
	cin>>k;
	set<char>pk = {'A','C','G','T'};
	for(i = 0,mx = 0,p = 0;i<ll(k.size());i++){
		if(pk.count(k[i])){
			p++;
		}else{
			mx = max(mx,p);
			p = 0;
		}
	}
	mx = max(mx,p);
	cout<<mx<<'\n';
}