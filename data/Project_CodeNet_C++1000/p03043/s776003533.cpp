#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
  // input
    long n,k;cin >> n >> k;

  // compute
    vector<int> a(n + 1);
    vector<int> p(n + 1);
    vector<int> ts(18);
    long sum = 0;
    long div = 0;
    double ans;
    for(long i = 1; i < n + 1; i++) a[i] = (k + (i-1)) / i;

    //2 square
    ts[0] = 1;
    for(int i = 1; i < 18; i++) ts[i] = 2 * ts[i - 1];   

    for(int i = 1; i < n + 1; i++) {
        if( k <= i){
          p[i] = 0;
          continue;
        }           
        for(int j = 0; j < 18; j++){     	
            if(ts[j] < a[i] && a[i] <= ts[j + 1]){
                p[i] = j + 1;
            }
        }
    }
  
    //debug
    //debug for(int i = 1; i < n + 1; i++) cout << p[i] << endl;

    for(int i = 1; i < n + 1; i++) sum += ts[17 - p[i]]; 
    div = ts[17] * n;
  
    //debug
    //debug for(int i = 1; i < 18; i++) cout << i << " " << ts[i] << endl;
  	//debug cout << sum << " " << div << endl;

    ans = (double)sum / (double)div;

  // output  
    cout << fixed << setprecision(12);
    cout << ans << endl;
}
