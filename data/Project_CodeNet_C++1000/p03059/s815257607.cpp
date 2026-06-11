#include<bits/stdc++.h>
using namespace std;

float A, B, T;


int main()
{

    cin >> A >> B >> T;
    float res = 0;
    for(int i = 1; T - i*A >= 0; ++i )
    {
        res += B;
    }
    cout <<  res << endl ;
}