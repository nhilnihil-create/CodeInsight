#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, n) for (int i = 1; i < (int)(n); i++)
int main()
{
    int a,b,c;
    int D;
    cin >> a >> b >> c >> D;
    if(abs(a - c) <= D)
    {
        cout << "Yes";
    }
    else if(abs(b - a) <= D && abs(c - b <= D))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    
}
