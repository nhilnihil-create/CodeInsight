#include<bits/stdc++.h>
using namespace std;

int main()
{
    string st;
    cin >> st;
    int Count = 0;
    for(int i = 0;i < 4; i++)
    {
        if(st[i] == '2')
        {
            Count++;
        }
    }
    cout << Count << endl;
    return 0;
}
