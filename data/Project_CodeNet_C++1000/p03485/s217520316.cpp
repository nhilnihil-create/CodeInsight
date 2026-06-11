#include <bits/stdc++.h>
#include <vector>
#include <math.h>

using namespace std;
 int main(){

  long long a,b; cin>>a>>b;
  float avg = (a+b)/2.0;

  //cout<<avg<<endl;

  if(avg == int(avg))
  cout<<avg<<endl;
  else
    cout<<int(avg)+1<<endl;

 return 0;
 }





