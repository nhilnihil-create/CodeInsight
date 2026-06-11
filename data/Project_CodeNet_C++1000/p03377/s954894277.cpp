#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main()
{
    int A,B,X;
    cin >> A >> B >> X;
    int remain = X - A;
    if(remain < 0)
    {
        cout << "NO";
    }
    else if(remain <= B)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}