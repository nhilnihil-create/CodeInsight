#include <iostream>

using namespace std;

int main()
{
    int A ,B ,C ;
    cin >> A>>B>>C ;
    if (A+B>=C&&1<=A<=500&&1<=B<=500&&1<=C<=1000)
    {
        cout << "Yes" ;

    }else if (C>A+B&&1<=A<=500&&1<=B<=500&&1<=C<=1000)
        cout << "No" ;

    }


