#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int n;cin>>n;
    if(n%2 == 0){
      cout<<n/2*n/2;
    }
    else{
      int a = (n-1)/2;
      int b = n-a;
      cout<<a*b;
    }
    return 0;
}