#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int x;
    cin >> x;
    vector<bool> expo(x+1);

    expo.at(1) = 1;
    for(int b = 2; b <= x; b++){
        int v = b * b;
        while(v <= x){
            expo.at(v) = 1;
            v *= b;
        }
    }
    for(int i = x; i >= 1; i--){
        if(expo[i]){
            cout << i << endl;
            return 0;
        }
    }
}