#include <bits/stdc++.h>

using namespace std;

template<typename type>
inline type Sum(type n)
{
    return n*(n+1)/2;
}

int main()
{
    int a,b;
    cin >> a >> b;
    cout << (b-a)*(b-a+1)/2-b << endl;
}