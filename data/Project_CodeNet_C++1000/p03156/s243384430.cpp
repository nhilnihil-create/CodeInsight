#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std ;

int main()
{
  int N,A,B ;
  cin>>N>>A>>B ;
  vector<int>P(N) ;
  for(int i=0;i<N;i++) cin>>P.at(i) ;
  
  sort(P.begin(),P.end()) ;
  int num_1=0,num_2=0,num_3=0 ;
  for(int i=0;i<N;i++){
    if(P.at(i)<=A) num_1++ ;
    else if(A+1<=P.at(i)&&P.at(i)<=B) num_2++ ;
    else if(B+1<=P.at(i)) num_3++ ;
  }
  int X=(num_1<num_2?num_1:num_2) ;
  cout<<(X<num_3?X:num_3)<<endl ;
  
  return 0 ;
}