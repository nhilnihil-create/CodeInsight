#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;
    if(n.size()==2){
        cout << n;
    }
    else{
        cout << n.at(2) << n.at(1) << n.at(0);
    }
}