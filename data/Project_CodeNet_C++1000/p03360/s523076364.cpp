#include<iostream>
#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int max(int a, int b ){
    if(a>=b) return a;
     return b ;
}

int main() {
	
    int a,b,c,k ;
    cin >> a >> b >> c >> k ;
    int MAX = max(max(a,b),c) ;
    int ans = a+b+c-MAX ;

    for(int i=1;i<=k;i++){
        MAX *= 2 ;
    }    
    cout << ans+MAX << endl ;  
	return 0;
}

