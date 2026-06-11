#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <map>
#include <set>
#include <ios>     // std::left, std::right
#include <iomanip> // std::setw(int), std::setfill(char)
using namespace std;


int main(){ 
  int A,B,C;
  cin>>A>>B>>C;
  if(A==B && B==C){
    cout<<"Yes"<<"\n";
  }
  else{
    cout<<"No"<<"\n";
  }
return 0;
}
