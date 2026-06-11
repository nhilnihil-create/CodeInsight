#include<bits/stdc++.h>
using namespace std;
#define Mod(n) n % 1000000007
const int dx[8] = {1, 0, -1, 0, -1, 1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
 
int main()
{
    int N;
    cin >> N;
    double sum = 0;
    double x;
    string u;
    for(int i = 0;i < N;i++)
    {
        cin >> x >> u;
        if(u == "JPY")
            sum += x;
        else
            sum += (x * 380000);
    }
    cout << sum << '\n';
}