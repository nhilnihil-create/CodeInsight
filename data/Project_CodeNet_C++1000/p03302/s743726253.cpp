#include <bits/stdc++.h>
#include<iostream>
#include <string>
#include <typeinfo>
using namespace std;
 
int main() {
    int a,b,c,d;
    cin >> a >> b;
    c = a*b;
  	d = a+b;
  	if(c == 15)cout << "*" << endl;
  	else if(d == 15)cout << "+" << endl;
  	else cout << "x" << endl;

} 
