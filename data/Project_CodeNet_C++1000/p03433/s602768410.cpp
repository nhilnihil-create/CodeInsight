#include <iostream>

using namespace std;

int main()
{
    int a ,n, x ;
    cin>> n;
    cin>> a;
    if (n>500 ){
        x = n%500;
        if (x<=a) {
        cout<< "Yes";
        }
        else{
            cout<< "No";
        }
    }
    else if(a>0 && n<=a){
        cout<< "Yes";
    }
    else{
        cout<< "No";
    }
    return 0;
}
