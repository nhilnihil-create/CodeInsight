#include <bits/stdc++.h>
using namespace std;

int main(){

    int a, b, k;
    cin >> a >> b >> k;

    map<int, int> dict;
    for (int i=0; i<k; i++){
        int l, r;
        l = a+i;
        r = b-i;
        if (l <= b && r >= a){
            dict[l];
            dict[r];
        }
    }

    for (auto p: dict){
        auto key = p.first;
        cout << key << endl;
    }
    return 0;
}