#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> data(3);
  cin>>data.at(0);
  cin>>data.at(1);
  cin>>data.at(2);
  
  int k;
  cin>>k;
  
  sort(data.begin(),data.end());
  
  int answer=data.at(0)+data.at(1);
  
  for (int i=0;i<k;i++){
    data.at(2)*=2;
  }
  
  answer+=data.at(2);
  
  cout<<answer<<endl;
  
  
}

  











