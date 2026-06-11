#include<iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main(){
  char x,y,z; cin >> x >> y >> z;
  map<char,int>a;
    a['a']=1;
    a['b']=2;
    a['c']=3;
  cout << ( a[x]+a[y]+a[z]==6 ? "Yes":"No") << endl;
}