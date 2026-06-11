#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d,e,f;
    cin>> a>>b>>c>>d;
    e= a+b;
    f= c+d;
    if(e>f){
        cout<< "Left";
    }
    else if(f>e){
        cout<< "Right";
    }
    else{
        cout<< "Balanced";
    }
    return 0;
}
