#include <iostream>
using namespace std;

long long calc(long long n)
{
    if(n%2 == 0)
    {
        return n^((n/2)%2);
    }
    else
    {
        return ((n+1)/2)%2;
    }   
}

int main()
{
    long long a,b;
    cin >> a >> b;

    cout << (calc(b)^calc(a-1)) << endl;
}