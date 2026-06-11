#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;
 
int main() {
    //input
    int n;cin >> n;
    int m;cin >> m;
    vector<int> x(m + 1,0);for(int i = 1; i < m + 1;i++) cin >> x[i];
    x[0] = -100000000;

    if(n >= m){
        cout << 0 << endl;
        return 0;
    }

    //compute
    vector<int> b(m,0);
    b[0] = 100000000;
    long sum = 0;

    sort(x.begin(),x.end());
  
    for(int i = 1; i < m;i++){
        b[i] = x[i + 1] - x[i];
        sum += b[i];
    }
    
    sort(b.rbegin(),b.rend());

    for(int i = 1; i < n;i++){
        sum -= b[i];
    }

    //output
    cout << sum << endl;
}