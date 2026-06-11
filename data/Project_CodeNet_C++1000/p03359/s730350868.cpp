#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin>> a>>b;
    if(a>1){
        if(b<a){
         cout<<   a-1;
        }
        else{
            cout<< a;
        }
    }
    else {
        cout << 1;
    }
    return 0;
}