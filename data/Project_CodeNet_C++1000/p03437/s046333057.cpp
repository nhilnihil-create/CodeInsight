#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;

    if(X==Y)
    {
        cout << "-1" << endl;
    }
    else if(X % Y == 0 )
    {
        cout << "-1" << endl;
    }
    else if( Y==1)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << X << endl;
    }

}