#include <bits/stdc++.h>
using namespace std;
string N;
int main(){
  cin >> N ;
  if(N.at(0) == N.at(1) && N.at(1) == N.at(2) ){
    puts("Yes");
  }
  else if( N.at(1) == N.at(2) && N.at(2) == N.at(3)){
    puts("Yes");
  }
  else {
    puts("No");
  }
}