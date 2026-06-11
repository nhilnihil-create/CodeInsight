#include <bits/stdc++.h>
using namespace std;
string toString(int n)
{
    string str;
    stringstream ss;
    ss << n;
    ss >> str;
    return str;
}
string toNegativeBase(int n, int negBase)
{
    if (n == 0)
        return "0";

    string converted = "";
    while (n != 0)
    {
        int remainder = n % negBase;
        n /= negBase;
        if (remainder < 0)
        {
            remainder += (-negBase);
            n += 1;
        }
        converted = toString(remainder) + converted;
    }

    return converted;
}
int main()
{
    int n;
    cin>>n;
    int negBase = -2;
    cout << toNegativeBase(n, negBase); 
    return 0;
}
