#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    int a[100];
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        a[i] = s[i] - 48;
    }
    int minnn = 10000;

    for(int i = 2; i < s.size(); i++)
    {
        if(minnn > abs(100 * a[i - 2] + 10 * a[i - 1] + a[i] - 753))
        {
            minnn = abs(100 * a[i - 2] + 10 * a[i - 1] + a[i] - 753);
        }
    }

    cout << minnn;
}