#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int count1=0,count2=0;
    for(char i:s){
        if(i=='R')count1++;
        else count2++;
    }
    if(count1>count2) cout << "Yes" << endl;
    else cout << "No" << endl;
}
