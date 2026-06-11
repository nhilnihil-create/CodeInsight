
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
    int N, judge=0, count=0;
    ll max=LLONG_MIN, min=LLONG_MAX, value;
    
    cin >> N;
    
    rep(i,N) {
    cin >> value;
    if(value<min) min=value;
    if(value>max) max=value;
    }
    
    cout << max-min;
    
      
}