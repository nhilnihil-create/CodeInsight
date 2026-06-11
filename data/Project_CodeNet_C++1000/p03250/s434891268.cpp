#include<bits/stdc++.h>
#define ro(a) (a).begin(),(a).end()
using namespace std;
using ll = long long int;
string sk;
int main(){
	vector<ll> vo(3);
	for(ll &i:vo) cin>>i;
	sort(ro(vo));
	for(ll i = 2;i>=1;i--) sk+=to_string(vo[i]);
	cout<<stoll(sk)+vo[0]<<'\n'; 
}