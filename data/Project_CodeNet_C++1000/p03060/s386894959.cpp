#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum = 0;
    cin >> n;
    int a1[n], a2[n], dif[n];

    for(int i=0; i<n; i++){
        cin >> a1[i];
    }

    for(int i=0; i<n; i++){
        cin >> a2[i];
    }

    for(int i=0; i<n; i++){
        dif[i] = a1[i] - a2[i];
    }

    for(int i=0; i<n; i++){
        if(dif[i] > 0) sum += dif[i];
    }

    cout << sum << endl;

    return 0;
}