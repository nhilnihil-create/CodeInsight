#include <bits/stdc++.h>
using namespace std;








int main(){

  long long n,m;
  cin>>n>>m;
  

  vector<vector<long long>> data(n,vector<long long>(2));
  
  for (long long i=0;i<n;i++){
    long long a,b;
    cin>>a>>b;
    data.at(i).at(0)=a;
    data.at(i).at(1)=b;
  }
  
  sort(data.begin(),data.end());
  
  long long count=m;
  
  long long answer=0;
  
  for (long long i=0;i<n;i++){
    long long tmp;
    tmp=min(count,data.at(i).at(1));
    count-=tmp;
    answer+=data.at(i).at(0)*tmp;
    if (count==0){
      break;
    }
  }
  
  cout<<answer<<endl;
  
      
    
  
  

  
  

  

        
}