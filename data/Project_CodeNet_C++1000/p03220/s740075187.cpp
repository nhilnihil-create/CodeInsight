
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
    int N, index, judge=0, count=0;
    double T, A;
    long double min=LLONG_MAX, value;
    
    cin >> N >> T >> A;
    
    rep(i,N) {
      cin >> value;
      if(abs(A-(T-value*0.006))<min) {
        min = abs(A-(T-value*0.006));
        index = i+1;
      }
    }
    
    cout << index << endl;
    
      
}