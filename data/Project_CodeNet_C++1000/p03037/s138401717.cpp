#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,m;
    cin>>n>>m;
    long long int fl,fr;
    long long int l,r;
    cin>>l>>r;
    fl=l;fr=r;
    m--;
    while(m--){
    	cin>>l>>r;
    	if(l>fl){
    		fl=l;
		}
		if(r<fr){
			fr=r;
		}
	}
	if(fr<fl){
		cout<<"0";
	}
	else{
		long long int ans=fr-fl+1;
		cout<<ans;
	}
	return 0;
}