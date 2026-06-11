#include <bits/stdc++.h>
using namespace std;

int main(){
    int month, day;
    cin >> month >> day;
    if(month > day) cout << month-1 << endl;
    else cout << month << endl;
    return 0;   
}