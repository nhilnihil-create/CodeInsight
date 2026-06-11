#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t X,Y;
  cin>>X>>Y;
  if(X%Y==0)
    cout<<-1<<endl;
  else
    for(int64_t i=0;i<1000000000000000000;i++)
      if(X*i%Y!=0){
        cout<<X*i<<endl;
        return 0;
      }
}