#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    long a;cin>>a;
    int b;cin>>b;
    long c = pow(100,a);
    if(b == 100){b=101;}
    long k =c*b;
    cout<<k;
    return 0;
}