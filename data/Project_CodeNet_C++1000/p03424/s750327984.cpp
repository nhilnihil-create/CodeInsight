#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;
    string str;
    int cnt = 0;
    map<string, int> m;

    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> str;
        m[str]++;
    }

    for (auto itr : m){
        if (itr.second > 0) { 
            cnt++;
        }
    } 

    if(cnt == 3) cout << "Three";
    else cout << "Four";
    //
}
