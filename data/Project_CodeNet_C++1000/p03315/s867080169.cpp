#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int N = pow(10,5);

vector<bool> isp(N+1, true);

void sieve() {
  isp[0] = false;
  isp[1] = false;
  for (int i=2; pow(i,2)<=N; i++) {
    if (isp[i]) for(int j=2; i*j<=N; j++) isp[i*j] = false;
  }
}

int main() {
  string s;
  int counter=0;
  cin>>s;
  for(int i=0; i<4;i++){
  if(s.at(i)=='+')
  counter++;
  else
  counter--;}
  cout<<counter<<endl;}
