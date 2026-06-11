#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int n;cin>>n;
    int h[n];
    for(int i = 0;i<n;i++) cin>>h[i];
    sort(h,h+n);
    int g= 0;
    for(int i = 0;i<n-1;i++) g+= h[i];
    if(g > h[n-1]) cout<<"Yes";
    else cout<<"No";
    return 0;
}