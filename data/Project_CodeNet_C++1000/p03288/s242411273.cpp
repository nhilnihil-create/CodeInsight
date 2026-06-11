#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    if(n<1200) cout<<"ABC";
   	else cout<<((n<2800)?"ARC":"AGC");
  	return 0;
}