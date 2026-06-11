#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<char> s(n);
    for(int i = 0;i < n;i++)cin >> s.at(i);
    sort(s.begin(), s.end());
    int ans = 1;
    for(int i = 1;i < n;i++){
        if(s.at(i - 1) != s.at(i))ans++;
    }
    if(ans == 3)cout << "Three" << endl;
    else cout << "Four" << endl;
}