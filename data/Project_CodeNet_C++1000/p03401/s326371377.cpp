#include<iostream>
#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;


int main() {
    int n ;
    cin >> n  ;
    int a[n+2] ;
    a[0] = 0 ;
    a[n+1] = 0 ;

    int sum = 0 ;
    for(int i=1;i<=n;i++){
       cin >> a[i] ;
       sum+= abs(a[i]-a[i-1]) ;
    } 

    sum+=abs(a[n]-a[0]) ;

    for(int i=1;i<=n;i++){
        cout << sum-abs(a[i]-a[i-1])-abs(a[i+1]-a[i])+abs(a[i+1]-a[i-1]) << endl ;
    }
    

	return 0;
}

