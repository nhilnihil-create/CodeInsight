#include <bits/stdc++.h> 
using namespace std; 

int main() {
     int n;
     cin >> n;
     
     int temp = n, divider = 0;
     for(;temp != 0; temp/=10)
          divider += temp%10;
          
     if(n%divider == 0)
          cout << "Yes";
     else
          cout << "No";
     
    return 0; 
} 