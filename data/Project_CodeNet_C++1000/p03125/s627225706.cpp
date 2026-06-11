#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    cin >> x >> y;

    cout << (y%x==0?y+x:y-x);
}