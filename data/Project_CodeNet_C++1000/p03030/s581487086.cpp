#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<tuple<string,int,int>> T;
    for(int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        x *= -1;
        T.push_back(make_tuple(s,x,i+1));
    }
    sort(T.begin(),T.end());
    for(int i = 0; i < n; i++) {
        cout << get<2>(T[i]) << "\n";
    }
    return 0;
}