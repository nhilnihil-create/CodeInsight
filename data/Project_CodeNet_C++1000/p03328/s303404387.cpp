#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main(void){
    int x1, x2;
    cin >> x1 >> x2;

    int n = x2 - x1 - 1;

    int h = n*(n+1)/2;
    cout << h - x1;
    return 0;
}