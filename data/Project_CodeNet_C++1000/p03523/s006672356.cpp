#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    string s;
    cin >> s;
    bool flag = false;
    string t[] = {
        "AKIHABARA", "AKIHABAR", "AKIHABRA", "AKIHABR", "AKIHBARA", "AKIHBAR",
        "AKIHBRA",   "AKIHBR",   "KIHABARA", "KIHABAR", "KIHABRA",  "KIHABR",
        "KIHBR",     "KIHHBARA", "KIHBRA",   "KIHBAR"
    };

    rep(i,2*2*2*2){
        if(t[i]==s){
            flag = true;
            break;
        }
    }

    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}