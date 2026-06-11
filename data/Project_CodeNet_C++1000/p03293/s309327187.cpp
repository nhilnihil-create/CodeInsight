#include<bits/stdc++.h>
using namespace std;
int main()
{
    string S, T;
    cin >> S >> T;

    string S2 = S + S;
    long long int p = S2.find(T);
    if(p == S2.npos)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
    return 0;
}
