#include<iostream>
using namespace std;
int main()
{
    int n, l[100], s = 0;
    cin >> n;
    int maxx = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> l[i];
        if(maxx < l[i])
        {
            maxx = l[i];
        }
        s = s + l[i];
    }
    if(maxx + maxx < s)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}