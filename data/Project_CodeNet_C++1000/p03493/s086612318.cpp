#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin >> a;
    cout << (a / 100) + ((a / 10) - ((a / 100) * 10)) + ((a / 1) - ((a / 100) * 100) - ((a / 10) - ((a / 100) * 10)) * 10) << endl;
}