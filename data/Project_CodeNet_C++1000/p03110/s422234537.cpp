#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    double x[100];
    string u[100];
    double n, s = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> u[i];
        if(u[i] == "BTC")
            s = s + x[i] * 380000;
        if(u[i] == "JPY")
            s = s + x[i];
    }
    cout << s;
    return 0;
}