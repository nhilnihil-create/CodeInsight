#include <iostream>
using namespace std ;
int main()
{
    int A , B , C ;
    cin >> A >> B >> C ;
    if (A >= -100 && C <=100)
    {
        if (A == B)
            cout << C ;


        if (B == C)
            cout << A ;

        if (A == C)
            cout << B ;

    }




}