#include <bits/stdc++.h>
using namespace std;






int main(){
  


  long long n;
  cin>>n;
  

  vector<long long> data(5);
  
  for (long long i=0;i<n;i++){
    string tmp;
    cin>>tmp;
    
    if (tmp.at(0)=='M'){
      data.at(0)++;
    }
    if (tmp.at(0)=='A'){
      data.at(1)++;
    }
    if (tmp.at(0)=='R'){
      data.at(2)++;
    }
    if (tmp.at(0)=='C'){
      data.at(3)++;
    }
    if (tmp.at(0)=='H'){
      data.at(4)++;
    }
    
  }
  
  
  long long answer=0;
  

  vector<long long> v={0,0,1,1,1};
  do{  
    long long tmp=1;
    for (long long i=0;i<5;i++){
      if (v.at(i)){
        tmp*=data.at(i);
      }
    }
  answer+=tmp;

  }while(next_permutation(v.begin(),v.end()));
  

  cout<<answer<<endl;

  


    
  
  
  
}