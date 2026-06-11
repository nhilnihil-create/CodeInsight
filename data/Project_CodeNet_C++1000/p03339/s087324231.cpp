#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >>n;
  string s;
  cin >>s;
  int p=300010;
  vector<int>vec(n);
  int a=0;
  for(int i=0;i<n;i++){
    if(s[i]=='E'){
      a++;
    }
    vec.at(i)=a;
  }
  for(int i=0;i<n;i++){
    int sum=0;
    if(i>=1){
      sum=i-vec.at(i-1)+vec.at(n-1)-vec.at(i);
    }
    else{
      sum=vec.at(n-1)-vec.at(0);
    }
    p=min(sum,p);
      
  }
  cout << p <<endl;
}
      
