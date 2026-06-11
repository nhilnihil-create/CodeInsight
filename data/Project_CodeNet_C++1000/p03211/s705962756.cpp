#include<bits/stdc++.h>
#include <vector>

using namespace std;

int main(){

 int_fast64_t s; cin>>s;

 int c = 1000;

 while(s>=100){

  int finds = s%1000;
  //cout<<finds<<" "<<c<<endl;
  int mini = abs(finds-753);
   c = min(c,mini);
   s = s/10;
}

 cout<<c<<endl;

return 0;
}
