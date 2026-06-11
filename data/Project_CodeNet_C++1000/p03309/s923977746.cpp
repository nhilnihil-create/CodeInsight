#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n,b;
  long long sum=0;
  cin>>n;
  vector<int> a;
  for(int i=0;i<n;i++){
    int in;
    cin>>in;
    a.push_back(in-i-1);
  }
  sort(a.begin(),a.end());
  if(n%2!=0){
    b=a.at((n-1)/2);
  }else{
    b=(a.at(n/2-1)+a.at(n/2))/2;
  }
  for(int i=0;i<n;i++){
    sum+=abs(a.at(i)-b);
  }
  cout<<sum<<endl;
}