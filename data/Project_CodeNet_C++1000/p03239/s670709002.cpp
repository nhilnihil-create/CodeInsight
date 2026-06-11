#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n,t,min=1001;
  cin >> n >> t;
  vector<int>c(n),x(n);
  for(int i=0; i<n; i++){
    cin >> c.at(i) >> x.at(i);
    if(x.at(i)<=t){
      if(min>c.at(i)){
        min=c.at(i);
      }
    }
  }
  if(min==1001){
    cout << "TLE" << endl;
  }
  else{
    cout << min << endl;
  }
}
