#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {

    ios::sync_with_stdio(false);
    
   int a, b, x,y,z;
   
   cin >> a >> b;
   
   x = a+b;
   y = a-b;
   z = a*b;
   
   cout << max(max(x,y),z) << endl;
   
   
    return 0;
}