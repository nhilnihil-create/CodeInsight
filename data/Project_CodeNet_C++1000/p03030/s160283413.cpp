#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    pair<pair<string, int> , int> book[n];
    for (size_t i = 0; i < n; i++) {
        string s;
        int p;
        cin >> s >> p;
        book[i] = make_pair(make_pair(s, -p), i+1);
    }

    sort(book, book+n);
    for (size_t i = 0; i < n; i++) cout << book[i].second << endl;
    return 0;
}
