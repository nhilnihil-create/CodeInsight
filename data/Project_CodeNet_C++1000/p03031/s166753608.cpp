#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  int k[m],s[m][10];
  for(int i=0;i<m;i++){
    cin>>k[i];
    for(int j=0;j<k[i];j++){
      cin>>s[i][j];
    s[i][j]--;
    }
  }
  int p[m];
  for(int i=0;i<m;i++) cin>>p[i];
  	int ans=0;
 	 for(int bit=0;bit<(1<<n);bit++){
    	int a=0;
    
    	for(int i=0;i<m;i++){
      	  int count=0;	
          for(int j=0;j<k[i];j++){
        		if(bit&(1<<s[i][j])) count++;
            }
            if(count%2==p[i]) a++;
        }
	    if(a==m) ans++;
     }

  cout<<ans<<endl;
  return 0;
}
