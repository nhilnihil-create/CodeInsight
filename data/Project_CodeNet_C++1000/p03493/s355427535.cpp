#include <iostream>

using namespace std;

int main()
{
    int a=0;
    string l;
    cin>> l;
    for (int i=0;i<3;i++){
        if(l[i]=='1'){
          a++ ;
        }

    }
    cout<< a;
    return 0;
}