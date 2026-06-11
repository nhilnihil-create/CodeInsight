#include <bits/stdc++.h>
#include<iostream>
using namespace std;
 
int main() {
    int a(0),b,c,ans(0),tmp(0);
  	string s;
  	//vector<>x();
  	cin >> s;
  	for(int i = 0;i < 3;i++){
  		if(s.at(i) == '1'){
          s.at(i) = '9';
        }else{
           s.at(i) = '1';
        }
    }
  	cout << s;
  
}
   
