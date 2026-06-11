#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a(3);
    for(int i = 0;i < 3;i++){
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    cout << abs(a.at(1) - a.at(0)) + abs(a.at(2) - a.at(1)) << endl;
}