#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int m=1e9+7;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    fastio
    int a,b,k;
    cin>>a>>b>>k;
    for(int i=min(a,b);i>0;--i){
    	if(a%i==0 && b%i==0) --k;
    	if(k==0){
    		cout<<i;
    		break;
    	}
    }
	return 0;
}