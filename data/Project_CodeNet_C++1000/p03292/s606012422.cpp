#include <bits/stdc++.h>
#include<iostream>
#include <string>
#include <typeinfo>
using namespace std;
 
int main() {
  vector<int>a(3);
    for(int i = 0;i < 3;i++)cin >> a[i];
  sort(a.begin(),a.end());
  
  int ans;
  int tmp = a[0] - a[1];
  ans = abs(a[1] - a[2] + tmp);
cout << ans;
} 
