#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    rep(i, n) cin >> vec[i];
    
    int a = 0, b = 0;
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    for(int i = 0; i < n; i += 2){
        a += vec[i];
        b += vec[i + 1];
    }
    
    cout << a - b << endl;
}