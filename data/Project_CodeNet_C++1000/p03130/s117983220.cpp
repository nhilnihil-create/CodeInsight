#include<bits/stdc++.h>

using namespace std;

int  main(){
 
  int dis[ 10];
  fill( dis,dis+10 , 0);
  
  for(int i=0 ; i <3;i++)
  {
    int a,b;
    cin>>a>>b;
    dis[a]++;
    dis[b]++;
    
    
  }
  
  int flag = 0 ;
  for( int i=1 ;i <5;i++)
    if( dis[i] > 2)
      flag =1;
  
  if( flag ==1  )
    cout<<"NO";
  else
    cout<<"YES";
  
  
  
  
}