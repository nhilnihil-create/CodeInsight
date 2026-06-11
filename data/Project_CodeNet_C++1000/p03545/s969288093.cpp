#include <iostream>
#include <vector>
#include <cstdlib>
#include <bits/stdc++.h>
#include <string>
#include <sstream>
using namespace std;
int main(){
  string a;
  cin >> a;
  int i = a[0]-'0';
  int j = a[1]-'0';
  int k = a[2]-'0';
  int l = a[3]-'0';
  if((i+j+k+l) == 7){
    cout <<i<<"+"<<j<<"+"<<k<<"+"<<l<<"=7\n";
  }
  else if((i+j+k-l) == 7){
    cout <<i<<"+"<<j<<"+"<<k<<"-"<<l<<"=7\n";
  }
  else if((i+j-k+l) == 7){
    cout <<i<<"+"<<j<<"-"<<k<<"+"<<l<<"=7\n";
  }
  else if((i-j+k+l) == 7){
    cout <<i<<"-"<<j<<"+"<<k<<"+"<<l<<"=7\n";
  }
  else if((i+j-k-l) == 7){
    cout <<i<<"+"<<j<<"-"<<k<<"-"<<l<<"=7\n";
  }
  else if((i-j+k-l) == 7){
    cout <<i<<"-"<<j<<"+"<<k<<"-"<<l<<"=7\n";
  }
  else if((i-j-k+l) == 7){
    cout <<i<<"-"<<j<<"-"<<k<<"+"<<l<<"=7\n";
  }
  else if((i-j-k-l) == 7){
    cout <<i<<"-"<<j<<"-"<<k<<"-"<<l<<"=7\n";
  }
  return 0;
}