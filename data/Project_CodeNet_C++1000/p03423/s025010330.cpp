#include<iostream>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    int n ;
    cin >> n  ;
  
    if(n%3<2)
    {
      cout << floor(n/3) ;
    }else
    {
      cout << n/3 ;
    }

	return 0;
}

