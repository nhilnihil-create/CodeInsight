#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

int main()
{
  int N ;
  cin>>N ;
  vector<int>a(N) ;
  for(int i=0;i<N;i++) cin>>a.at(i) ;
  sort(a.begin(),a.end()) ;
  reverse(a.begin(),a.end()) ;
 
  if(N==2){
    cout<<a.at(0)<<" "<<a.at(1)<<endl ;
    return 0 ;
  }
  int center ;
  int m,n ;
  if(a.at(0)%2==0) center=a.at(0)/2 ;
  else center=(a.at(0)+1)/2 ;
  int min_dif=1e9 ;
  for(int i=1;i<N;i++){
    if((a.at(0)%2==0&&a.at(i)==center)||(a.at(0)%2!=0&&(a.at(i)==center||a.at(i)==center-1))){
      cout<<a.at(0)<<" "<<a.at(i)<<endl ;
      return 0 ;
    }else{
      int dif ;
      if(a.at(0)%2==0){
        dif=(a.at(i)>center?a.at(i)-center:center-a.at(i)) ;
        if(min_dif>dif){
          min_dif=dif ;
          n=a.at(i) ;
        }
      }else{
        dif=(a.at(i)>center?a.at(i)-center:center-a.at(i)) ;
        if(min_dif>dif){
          min_dif=dif ;
          n=a.at(i) ;
        }
      }
    }
  }
  m=a.at(0) ;
  cout<<m<<" "<<n<<endl ;
  
  return 0 ;
}
