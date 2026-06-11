#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int max_count = 0;

    for(int i=1; i<n; i++) {
        string a = s.substr(0,i);
        string b = s.substr(i,n-i);
        int count = 0;
        for(char c = 'a'; c <= 'z'; c++) {
            if(a.find(c) != string::npos && b.find(c)!= string::npos) count++;
        }
        max_count = max(count, max_count);
    }
    cout << max_count << endl;
}
