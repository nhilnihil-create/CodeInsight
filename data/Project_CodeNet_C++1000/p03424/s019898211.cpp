#include<bits/stdc++.h>
using namespace std;
//KASRA FOULADI;
int main(){
    int n, ans = 0;
    char c;
    cin >> n;
    int cnt[256] = {};
    for(int i = 0; i < n; ++i){
        cin >> c;
        cnt[c] = 1;
    }
    for(int i = 0; i < 256; ++i)
        ans += cnt[i];
    if(ans == 1)
        cout << "One" << '\n';
    else if(ans == 2)
        cout << "Two" << '\n';
    else if(ans == 3)
        cout << "Three" << '\n';
    else
        cout << "Four" << '\n';
}