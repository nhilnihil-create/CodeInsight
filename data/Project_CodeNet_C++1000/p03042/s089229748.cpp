#include<iostream>
using namespace std;
int main (void){

    int n,y,m,yy,mm,a,b;

    cin >> n;

    a = n / 100;
    b = n % 100;

    if(0 < a && a < 13)
    m = 1,y = 0;
    else
    y = 1,m = 0;

    if(0 < b && b < 13 )
    mm = 1,yy = 0;
    else
    yy = 1,mm = 0;

    if(y == 1 && mm == 1)
    cout << "YYMM" << endl;
        
    else if(m == 1 && yy == 1)
    cout << "MMYY" << endl;
    
    else if(m == 1 && mm == 1)
    cout << "AMBIGUOUS" << endl;
    
    else
    cout << "NA" << endl;

    return 0;
}