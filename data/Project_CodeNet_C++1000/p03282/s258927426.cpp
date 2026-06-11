#include <bits/stdc++.h>
using namespace std;

int conv(char c){
    for (int i = 50; i<=57; i++){
        if (c == i){
            return i-48;
        }
    }
}

int main(){

    string s;
    cin >> s;

    int64_t k;
    cin >> k;

    int answer = 1;
    for (int64_t i = 0; i<k; i++){
        if (s.at(i) != '1'){
            answer = conv(s.at(i));
            break;
        }
    }

    cout << answer << endl;
}