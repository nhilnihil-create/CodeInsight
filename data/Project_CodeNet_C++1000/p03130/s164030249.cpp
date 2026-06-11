#include<iostream>
using namespace std ;

int main()
{
  int a[3],b[3] ;
  for(int i=0;i<3;i++) cin>>a[i]>>b[i] ;
  
  int c[6]={a[0],a[1],a[2],b[0],b[1],b[2]} ;
  int count[4]={0} ;
  for(int i=0;i<6;i++){
    switch(c[i]){
      case 1: count[0]++ ;
              break ;
      case 2: count[1]++ ;
              break ;
      case 3: count[2]++ ;
              break  ;
      case 4: count[3]++ ;
              break ;
    }
  }
  
  if(count[0]*count[1]*count[2]*count[3]==4&&
        count[0]+count[1]+count[2]+count[3]==6){
    cout<<"YES"<<endl ;
  }else cout<<"NO"<<endl ;
       
  
  return 0 ;
}
