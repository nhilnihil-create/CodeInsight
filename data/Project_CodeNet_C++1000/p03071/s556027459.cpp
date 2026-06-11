#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int a,b;cin>>a>>b;
    if(a>b) cout<<a+a-1;
    if(a==b)cout<<a+b;
    if(a<b) cout<<b+b-1;
    return 0;
}