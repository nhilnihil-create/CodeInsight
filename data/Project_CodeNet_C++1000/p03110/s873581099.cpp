#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<pair<double,string>> vec(n);
  int i;
  for(i=0;i<n;i++){
    double a;
    string s;
    cin >> a >> s;
    vec.at(i)=make_pair(a,s);
  }
  double sum=0;
  for(i=0;i<n;i++){
    if(vec.at(i).second=="BTC"){
      vec.at(i).first*=380000;
    }
  }
  for(i=0;i<n;i++){
    sum+=vec.at(i).first;
  }
  cout << sum;
}
    
  
  
  