#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin>>a;
  
  vector<double> vec(a);
  double sum=0;
  
  for(int i=0;i<a;i++){
    cin>>vec.at(i);
    sum+=vec.at(i);
    }
  
  double heikin=sum/a;
  int answer=0;
  double sa=1000;
  
  for(int i=0;i<a;i++){
    if(abs(heikin-vec.at(i))<sa){
      answer=i;
      sa=abs(heikin-vec.at(i));
    }
  }
  
  cout<<answer<<endl;
}