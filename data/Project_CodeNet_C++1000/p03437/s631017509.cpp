#include <bits/stdc++.h>
using namespace std;


int main() {

long X,Y;
cin>>X>>Y;

if(X%Y==0){
  cout<<-1<<endl;
  return 0;
}

cout<<X*(Y-1)<<endl;

}
