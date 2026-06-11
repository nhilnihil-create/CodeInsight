#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    int ar[t];
    for(int i=0;i<t;++i) cin>>ar[i];
  	int mx=*max_element(ar,ar+t);
  	int mi=*min_element(ar,ar+t);
  	cout<<mx-mi;
  	return 0;
}