#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    map<string, int> dict;

    
    string buf, memo;
    cin >> memo;
    dict[memo]++;
    for (int i=1; i<n; i++){
        cin >> buf;
        dict[buf]++;

        if (buf.at(0) != memo.at(memo.size()-1)){
            cout << "No" << endl;
            return 0;
        }
        memo = buf;
    }

    for (auto p: dict){
        auto value = p.second;

        if (value != 1){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}