#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;

int main(){
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> v;
    for (int i = min(a,b); i >= 1; i--) {
        if (a%i == 0 && b%i == 0){
            k--;
            if(k == 0) {
                cout << i << endl;
                return 0;
            }
        }
    }
}