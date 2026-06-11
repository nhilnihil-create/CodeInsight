#include<iostream>
using namespace std;
int main(void)
{
    int a,b,x;
    cin >> a >> b >> x;
    for(int i=0;i<=b;i++)
        if(a+i==x)
        {
            cout << "YES";
            return 0;
        }
    cout << "NO";
    return 0;
}
