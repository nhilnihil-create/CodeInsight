#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a;
    cin >> n >> a;
    int l = n%500;
    if(l<=a)
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
}
