#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
  
        int n,i,cnt=0;
        scanf("%d",&n);
        string a,b,c;
        cin>>a>>b>>c;
        for(i=0;i<n;++i)
            {
                if(a[i]==b[i] && b[i]!=c[i])
                   cnt++;
                   
                else if(a[i]!=b[i] && b[i]==c[i])
                          cnt++;
                          
                else if(a[i]==c[i] && b[i]!=c[i])
                          cnt++;          
                          
                else if(a[i]!=b[i] && b[i]!=c[i])
                          cnt+=2;          
            }
            
            printf("%d",cnt);
           
    
    	return 0;
} 