#include <bits/stdc++.h>

using namespace std;

// Function come here..
int p(int a, int b, int c)
{
    return (a + b + c) / 2;
}
int foo(int a, int b, int c)
{
    int pi = p(a, b, c);
    return sqrt(pi * (pi - a) * (pi - b) * (pi - c));
}

int main(int argc, char **argv)
{
    // Problem solution come here...
    int a, b, c;
    cin >> a >> b >> c;
    cout << foo(a, b, c) << endl;
    return 0;
}