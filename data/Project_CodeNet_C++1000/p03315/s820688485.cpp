#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main(){
    string s;
    cin >> s;
    int ret = 0;
    for(auto&& c:s){
        if(c == '+')ret++;
        else ret--;
    }
    cout << ret << endl;
    return 0;
}