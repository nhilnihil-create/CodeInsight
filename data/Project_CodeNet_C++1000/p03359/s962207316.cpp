#include<iostream>
#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	
    int a,b ;
    cin >> a >> b ;

    int ans = a ;
    if(b<a) ans-=1 ;
    
    cout << ans << endl ;  
	return 0;
}

