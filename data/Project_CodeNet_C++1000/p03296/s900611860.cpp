#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;

int main(){
    using namespace std;
    int n;
    cin >> n;
    vector <int> data(n);
    rep(i, n) cin >> data[i];
    bool flag = false;
    int cnt = 0;
    rep(j, n - 1) {
        if (flag) {
            flag = false;
            continue;
        }
        if (data[j + 1] == data[j]) {
            flag = true;
            ++cnt;
        }
    }
    cout << cnt << endl;
    
    return 0;
}