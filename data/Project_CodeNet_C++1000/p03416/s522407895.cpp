#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a, b, cnt=0, tmp;
    cin >> a >> b;
    for (int i=a; i<=b; i++){
        vector<char> str;
        bool flag = true;
        tmp = i;
        while (tmp != 0){
            str.emplace_back(tmp % 10 - '0');
            tmp /= 10;
        }
        for (int i=0; i<str.size()/2; i++){
            if (str[i] != str[str.size()-1-i]) flag = false;
        }
        if (flag) cnt++;
    }
    cout << cnt << endl;
    return 0;
}