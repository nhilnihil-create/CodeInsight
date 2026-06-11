#include<iostream>
#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	
    int a,b,x ;
    cin >> a >> b >> x ;
  
    if(a>x) cout << "NO" ;
    if(a==x) cout << "YES" ;
    if(a<x){
      if(b>=(x-a)){
        cout << "YES" ;
      }else{
                cout << "NO" ;
      }
    } 
  
  cout << endl ;
	return 0;
}

