#include<iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

long long x,y ;
cin >> x >> y ;

int cnt = 0 ;
while(x<=y)
{
    x = x*2 ;
    ++cnt ;
}
 cout << cnt << endl ;

	return 0;
}

