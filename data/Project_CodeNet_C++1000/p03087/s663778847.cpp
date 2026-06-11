#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q,l,r,ac[100005];
	string s;
    cin>>n>>q>>s;
    ac[0]=0;
    for(int i=1;i<n;i++){
    	if(s[i]=='C'&&s[i-1]=='A') ac[i]=ac[i-1]+1;
        else ac[i]=ac[i-1];
    }
    for(int i=0;i<q;i++){
    	cin>>l>>r;
        l--;r--;
        cout<<ac[r]-ac[l]<<endl;
    }
}