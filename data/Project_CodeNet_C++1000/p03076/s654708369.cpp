#include <bits/stdc++.h>
using namespace std;


int main(){

  vector<int> tim(5);
  int minwk=125;
  int min_index=0;
  for(int i=0;i<5;i++){
    cin>>tim.at(i);
    int rem=tim.at(i)%10;
    
    if(rem<minwk&&rem!=0){
      min_index=i;
      minwk=rem;
    }
  }

  int sum=0;
  for(int i=0;i<5;i++){
    if(i!=min_index)
      sum+=((tim.at(i)+9)/10)*10;
  }

  cout<<sum+tim.at(min_index)<<endl;

  return 0;

}
