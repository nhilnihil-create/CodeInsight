#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int red=0; int blue=0;
    for(int i=0; i<s.length(); i++){
        if(s.at(i)=='0') red++;
        if(s.at(i)=='1') blue++;
    }
    int sum = 2 * min(red, blue);

    cout << sum << endl;
    return 0;
}