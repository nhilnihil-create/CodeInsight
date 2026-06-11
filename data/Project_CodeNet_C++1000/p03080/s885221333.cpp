#include <bits/stdc++.h>
using namespace std;

int main() {
int N;
string S;
int r=0;
int b=0;
cin >>N>>S;
for(int i=0;i<N;i++){
  if(S.at(i)=='R'){
    r++;
  }
  else if(S.at(i)=='B'){
    b++;
  }
}
if(r>b){
  cout <<"Yes"<<endl;
}
else if (r<=b){
  cout <<"No"<<endl;
}
}