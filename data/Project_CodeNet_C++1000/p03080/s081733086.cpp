#include <iostream>
using namespace std;

int main (void){
int c;
char x[101];
cin >> c;
cin >> x;
int r;
for (int i=0;i<c;i++){
  if (x[i]=='R') r++;
}
if(r>c-r){cout<<"Yes"<<endl;}
else{cout<<"No"<<endl;}
}