#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
   	#endif
    char c;
    int ans=0;
    while(cin>>c) if(c=='1') ++ans;
   	cout<<ans;
   	return 0;
}