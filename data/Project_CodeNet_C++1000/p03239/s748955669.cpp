#include<bits/stdc++.h>
using namespace std;

int main()
 {
	//code
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n,t,a,b,flag=0;
    int ans=10000;
    cin>>n>>t;
    while(n--){
        cin>>a>>b;
        if(b<=t){
            ans=min(ans,a);
            flag=1;
        }
       
    }
  if(flag==1){
      cout<<ans<<endl;
  }
  else
  cout<<"TLE"<<endl;
 
 
	return 0;
}