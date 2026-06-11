#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    string s;
    cin >> s;
    int count;
    int mx=100000000;
    for(int i=0; i<s.size()-2; i++){
        string num;
        num.push_back(s[i]);
        num.push_back(s[i+1]);
        num.push_back(s[i+2]);
        count = abs(stoi(num)-753);
        //cout << count <<endl;
        mx = min(count,mx);
    }
    cout << mx <<endl;
}