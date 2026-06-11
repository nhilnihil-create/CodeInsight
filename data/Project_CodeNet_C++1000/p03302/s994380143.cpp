#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> mp;
ll inf =  1e9;


int main(){
    ll a,b;
    cin>>a>>b;
    if( a + b == 15 ){
	cout<<'+'<<endl;
    }else if( a*b == 15 ){
	cout<<'*'<<endl;
    }else{
	cout<<'x'<<endl;
    }
    return 0;
}
