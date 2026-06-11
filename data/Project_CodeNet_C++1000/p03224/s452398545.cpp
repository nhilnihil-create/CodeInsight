#include <bits/stdc++.h>
#define PB push_back
#define LL long long
using namespace std;
int matrix[1000][1000];
int main() 
{
    int n;
    cin >> n;
    int Sz = -1;
    for(int sz = 2; sz <= 1000; sz++)
    {
        if(sz * (sz - 1) / 2 == n)
            Sz = sz;
    }
    
    if(Sz == -1)
    {
        cout << "No";
        return 0;
    }
    cout << "Yes" << endl;
    cout << Sz << endl;
    int ptr = 1;
    for(int i = 1; i <= Sz; i++)
    {
        for(int j = i + 1; j <= Sz; j++)
        {
            matrix[i][j] = matrix[j][i] = ptr++;
        }
    }
    for(int i = 1; i <= Sz; i++)
    {
        cout << Sz - 1 << " ";
        for(int j = 1; j <= Sz; j++)
        {
            if(j == i)
                continue;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}