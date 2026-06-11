#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string, bool> id;
    string s;
    //0を入力
    cout << 0 << endl;
    cout << flush;
    cin >> s;
    if (s == "Vacant") return 0;
    if (s == "Male"){
        id["Male"] = 0;
        id["Female"] = 1;
    }
    else {
        id["Male"] = 1;
        id["Female"] = 0;
    }
    //n-1を入力
    cout << n - 1 << endl;
    cout << flush;
    cin >> s;
    if (s == "Vacant") return 0;
    //ここからにぶたん
    int ok = 0;
    int ng = n - 1;
    while (abs(ok - ng) > 1){
        int mid = (ok + ng) / 2;
        cout << mid << endl;
        cout << flush;
        cin >> s;
        if (s == "Vacant") return 0;
        if (id[s] == mid % 2) ok = mid;
        else ng = mid;
    }
}