#include<bits/stdc++.h>
using namespace std;

int main()
{
    int S, A, B;

    cin >> S;

    A = S % 100;
    B = S / 100;

    if( ( A > 0 && A <= 12 ) && ( B > 0 && B <= 12 ) )
        cout << "AMBIGUOUS" << endl;
    else if( A > 0 && A <= 12 )
        cout << "YYMM" << endl;
    else if( B > 0 && B <= 12 )
        cout << "MMYY" << endl;
    else
        cout << "NA" << endl;

    return 0;
}
