#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main(void){
    cin >> n;
    cin >> s;
    int res = 0;
    for(int i = 0; i < s.size(); i++){
        string x, y;
        x = s.substr(0, i);
        y = s.substr(i);
        unordered_map<char, int> mx, my;
        for(auto j : x) mx[j] = 1;
        for(auto j : y) my[j] = 1;
        int tmp = 0;
        for(char c = 97; c <= 122; c++){
            tmp += mx[c]*my[c];
        }
        res = max(res, tmp);
    }
    cout << res << endl;
    return 0;
}
