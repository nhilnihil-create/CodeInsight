#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int cnt[3]{}, k;
    cin >> s;
    for(auto c : s){
        ++cnt[c-'a'];
    }
    // abcabc...のように並べるので
    k = *min_element(cnt,cnt+3);
    cout << (cnt[0]-k < 2 && cnt[1]-k < 2 && cnt[2]-k < 2 ? "YES" : "NO") << endl;
    return 0;
}
