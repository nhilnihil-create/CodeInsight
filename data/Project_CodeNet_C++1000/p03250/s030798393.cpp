#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int a[3];
    for(int i = 0;i<3;i++) cin>>a[i];
    sort(a,a+3);
    cout<<a[2]*10+a[0]+a[1];
    return 0;
}