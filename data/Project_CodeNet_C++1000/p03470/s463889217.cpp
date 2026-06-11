#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;



int main() {
  int n;
  cin >>n;
  vector<int> d(n);
  for (int i = 0; i <n; i++) 
  {
    cin >> d.at(i);
  }
  sort(d.begin(),d.end());
  //reverse(a.begin(),a.end());
  int sum =1;

  for(int i=0;i<n-1;i++){
  
    if(d.at(i)<d.at(i+1)){
      sum++;

  }

  
}
  cout<<sum<<endl;
}