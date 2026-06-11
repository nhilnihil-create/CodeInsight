#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main()
{
    int a,b,c,d;
    cin >> a;
    cin >> b;
    a = min(a,b);
    cin >> c;
    cin >> d;
    c = min(c,d);
    cout << a + c;
}