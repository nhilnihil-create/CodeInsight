#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if((a-1)*(b-1)*(c-1)*(d-1)==0&&(a-4)*(b-4)*(c-4)*(d-4)==0&&(a-7)*(b-7)*(c-7)*(d-7)==0&&(a-9)*(b-9)*(c-9)*(d-9)==0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}