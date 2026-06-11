#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    long long n;cin>>n;
    long long a[5];
    for(int i = 0;i<5;i++) cin>>a[i];
    sort(a,a+5);
    long long kai;
    if(n%a[0] == 0) kai = n/a[0];
    else kai = n/a[0]+1;
    cout<<4+kai;
    return 0;
}