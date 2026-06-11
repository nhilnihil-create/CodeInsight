#include <bits/stdc++.h>

using namespace std;


 
int main() {
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
     
    int n;
    cin>>n;
    long int a[n],b[n],h,w,cnt=0;
    cin>>h>>w;
    long int i;
    for(i=0;i<n;++i)
      {
          cin>>a[i]>>b[i];
          if(a[i]>=h && b[i]>=w)
            cnt++;
      }
      
      cout<<cnt;
      
	return 0;
	
} 