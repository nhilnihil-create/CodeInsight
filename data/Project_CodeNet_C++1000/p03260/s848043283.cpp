#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b; 
    cin >> a >> b; 

    bool yes = false; 
    for (int c = 1; c <= 3; c++)  {
        if (a * b * c % 2) yes = true; 
    }

    yes ? cout << "Yes\n" : cout << "No\n";
}