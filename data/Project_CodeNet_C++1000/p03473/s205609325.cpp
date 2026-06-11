#include <bits/stdc++.h>
using namespace std;

int main() {
    int GivenTime;
    int TimeOfDay = 24;
    
    cin >> GivenTime; 
    
    int NewYear = TimeOfDay + (TimeOfDay - GivenTime);
    
    cout << NewYear << endl;
}