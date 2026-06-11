#include <bits/stdc++.h>
using namespace std;
int main()
{
 int N, G = 0, P = 0, W = 0, Y = 0;
 string S;

 cin >> N;

for (int i = 0; i< N;i++)
{
    cin >> S;
    
    if (S == "G")
        G = 1;
    if (S == "P")
        P = 1;
    if (S == "W")
        W = 1;
    if (S == "Y")
        Y = 1;
}
    if (G + P + W + Y == 3)
        cout << "Three" << endl;
    else
        cout << "Four" << endl;

    return 0;
}