#include <bits/stdc++.h>
using namespace std;

int main() 
{
    char X, Y;
    cin >> X >> Y;
    if (X - 'Z' < Y - 'Z') {
        cout << "<" << endl; 
    }else if (X - 'Z' > Y - 'Z') {
        cout << ">" << endl;
    }else{
        cout << "=" << endl;
    }
}