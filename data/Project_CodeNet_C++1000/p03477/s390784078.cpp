#include <iostream>
#include <cmath>
using namespace std;





int main()
{

    int a, b,c,d,f,g;
    cin>> a;

    cin>>b;
    cin>> c;
    cin >>d ;
    f=(a+b);
    g=(c+d);
    if(f>g){
        cout<<"Left";
    }else if(f<g) {
        cout<<"Right";
    }else  {
        cout<<"Balanced";
    }



    return 0;
}
