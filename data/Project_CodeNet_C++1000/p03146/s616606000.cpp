#include<iostream>
using namespace std;
int main()
{
    int s, a[10000];
    cin >> s;
    a[0] = s;
    for(int i = 1; i < 10000; i++)
    {
        if(s % 2 == 0)
        {
            s = s / 2;
            a[i] = s;
        }
        else
        {
            s = 3 * s + 1;
            a[i] = s;
        }

        for(int j = 0; j < i; j++)
        {
            if(i != j && a[i] == a[j])
            {
                cout << i + 1;
                return 0;
            }
        }
    }
}