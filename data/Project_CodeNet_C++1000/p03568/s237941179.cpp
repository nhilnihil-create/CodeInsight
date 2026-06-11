#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
const long long INF = 1LL << 60;

int main() {
  int N; cin>>N;
  int odd=0;
  int even=0;
  for(int i=0; i<N; i++){
    int a; cin>>a;
    if(a%2==0) even++;
    if(a%2==1) odd++;;
  }
  cout<<pow(3, N)-pow(2, even)<<endl;
}