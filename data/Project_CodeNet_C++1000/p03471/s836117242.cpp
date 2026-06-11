#include<iostream>

using namespace std;

int n,y;
int s,g,i;

bool solve(){
  for(s=0;s<=n;s++){
    for(g=0;g<=n-s;g++){
      i=n-s-g;
      if(s*1000+g*5000+i*10000==y) return true;
    }}
  return false;
}

int main(){
  cin >> n >> y;

  if(solve()){
    cout << i << ' '  << g << ' ' << s << endl;}
  else{
    cout << "-1 -1 -1" << endl;}
  return 0;
}
