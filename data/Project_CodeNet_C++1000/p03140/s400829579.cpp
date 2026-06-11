#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int char_count(char a, char b, char c){
    set<char> se;
    se.insert(a); se.insert(b); se.insert(c);
    int n = se.size();
    return n-1;
}

int main(){
    int N; string a, b, c; cin >> N >> a >> b >> c;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += char_count(a[i], b[i], c[i]);
    }
    cout << ans << endl;
    return 0;
}