#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <cctype>
#define int long long
using namespace std;

void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

signed main() {

    int a,b,c,x;
    int n;
    int count = -1;
    int m[140000];
    int ans = 0;

    cin >> a >> b >> c >> x;
    n = (a+1)*(b+1)*(c+1);

    for(int i = 0; i < n; i ++){
        m[i] = 10000000;
    }

    for(int i = 0; i < a+1; i ++){
        for(int j = 0; j < b+1; j ++){
            for(int k = 0; k < c+1; k ++){
                count ++;
                m[count] = i*500 + j*100 + k*50;
            }
        }
    }

    for(int i = 0; i < n; i ++){
        if(m[i] == x) ans ++;
    }
    cout << ans;
    return 0;
}