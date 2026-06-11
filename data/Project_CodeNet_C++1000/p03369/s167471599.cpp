#include <iostream>

using namespace std;

int main()
{
    int a=7;
    string l;
    cin>> l;
    for (int i=0;i<3;i++){
        if(l[i]=='o'){
          a++ ;
        }

    }
    cout<< a*100;
    return 0;
}