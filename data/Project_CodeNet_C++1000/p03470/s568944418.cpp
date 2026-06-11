#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    rep(i, n) cin >> vec[i];
    
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    int cnt = 0;
    int before = 101;
    
    rep(i, n){
        if(before != vec[i]){
            cnt++;
            before = vec[i];
        }
    }
    
    cout << cnt << endl;
}