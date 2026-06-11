#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int x,y,xx,yy;cin>>x>>y>>xx>>yy;
    int a = x-xx;
    int b = y-yy;
    cout<<xx+b<<" "<<yy-a<<" "<<x+b<<" "<<y-a;
    return 0;
}