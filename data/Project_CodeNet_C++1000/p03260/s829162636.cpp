#include <bits/stdc++.h>
using namespace std;

int main(){

    int a, b, c=3;
    cin >> a >> b;
    while(c--){
        if(a*b*c % 2 != 0){
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    
    return 0;
}