#include <iostream>
using namespace std;

int main() {
int r,h,z;
cin>>r>>h>>z;
if (r==h)
cout<<z;
else if (h==z)
cout<<r;
else if (r==z)
cout<<h;
    return 0;
}