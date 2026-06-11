#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    bool flag = false;
    string S;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> S;
        if(S == "Y")flag = true;
    }
    if(flag)cout << "Four" << endl;
    else cout << "Three" << endl;
}