#include <iostream>

using namespace std;

int main()
{ int r;
int d;
int x;
cin>> r>>d>>x;
int y=x;
for(int i=0;i<10;i++){
    y=(r*y)-d;
    cout<<y<<endl;
}
    return 0;
}