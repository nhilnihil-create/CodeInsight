#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int) (n); i++)
#define _GLIBCXX_DEBUG

string s, ans;
int calc(string t){
    int ans = t[0] - '0';
    int i = 1;
    while(i < 7){
        char op = t[i], n = t[i+1];
        if(op == '+') ans += n - '0';
        if(op == '-') ans -= n - '0';
        i+=2;
    }
    return ans;
}

void brute(int k = 0){
    if(k == 3){
        if(calc(s) == 7) ans = s;
        return;
    }

    s.insert(k*2 + 1, "+");
    brute(k+1);
    s.erase(k*2+1, 1);
    s.insert(k*2 + 1, "-");
    brute(k+1);
    s.erase(k*2+1, 1);
}

int main(){
    cin >> s;

    brute(0);
    cout << ans << "=7" << endl;
}