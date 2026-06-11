#include <bits/stdc++.h>
using namespace std;
int main()
{
    int64_t A,B,C,K;
    cin >> A >> B >> C >> K;
    if(abs(A-B)>10e18) 
    {
        cout << "Unfair" << endl;
    return 0;
    }
    if(K%2==0) cout << A-B << endl;
    else
    {
        cout << B-A << endl;
    }
}