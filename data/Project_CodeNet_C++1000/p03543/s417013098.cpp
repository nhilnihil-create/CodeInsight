#include<bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin >> x;
    int memo1 = x / 1000;
    int memo2 = (x / 100) % 10;
    int memo3 = (x % 100) / 10;
    int memo4 = x % 10;
    if(memo1 == memo2 && memo2 == memo3){
        cout << "Yes" << endl;
    }
    else if(memo2 == memo3 && memo3 == memo4){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}