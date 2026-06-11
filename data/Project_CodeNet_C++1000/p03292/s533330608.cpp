#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int a[3];
    for(int i = 0;i<3;i++) cin>>a[i];
    int g[5];
    g[0] = abs(a[0]-a[1])+abs(a[1]-a[2]);
    g[1] = abs(a[0]-a[2])+abs(a[1]-a[2]);
    g[2] = abs(a[1]-a[0])+abs(a[0]-a[2]);
    g[3] = abs(a[1]-a[2])+abs(a[0]-a[2]);
    g[4] = abs(a[2]-a[1])+abs(a[0]-a[1]);
    g[5] = abs(a[2]-a[0])+abs(a[0]-a[1]);
    sort(g,g+5);
    cout<<g[0];
    return 0;
}