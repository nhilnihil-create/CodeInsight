#include <bits/stdc++.h>
using namespace std;

int main(){

  vector<int> data(3);
  cin>>data.at(0);
  cin>>data.at(1);
  cin>>data.at(2);
  
  sort(data.begin(),data.end());
  
  cout<<10*data.at(2)+data.at(0)+data.at(1)<<endl;
  
  
  
}
  











