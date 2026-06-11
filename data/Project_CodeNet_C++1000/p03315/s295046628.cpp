#include <bits/stdc++.h>
using namespace std;

int main() {
    int N = 0;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s.at(i) == '+' ){
            N++;
        }
        else if(s.at(i) == '-'){
            N -= 1;
        }
    }
    cout << N << endl;
}