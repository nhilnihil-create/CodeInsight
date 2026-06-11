#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[3] = {0};
    string s;
    cin >> s;

    for (char t : s){
        if (t == 'a')
            arr[0] ++;
        if (t == 'b')
            arr[1] ++;
        if (t == 'c')
            arr[2] ++;
    }
    
    int pr = 1;
    for (int i = 0; i < 3; i ++)
        pr *= arr[i];
    
    if (pr == 1)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}