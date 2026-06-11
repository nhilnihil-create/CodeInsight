#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  // input
    int n;cin >> n;
    vector<int> a(n + 1);
    vector<int> c(n + 1,0);
    int counter = 0;
    for(int i = 1; i < n + 1; i++) cin >> a[i];

  // compute
    for(int i = 1; i < n + 1; i++) {
        if(a[i] > n){
            counter += 1;
        }else{
            c[a[i]] += 1;
        }
    }

    for(int i = 1; i < n + 1; i++){
        if(c[i] - i > 0){
            counter += c[i] - i;
        }else if(c[i] - i < 0){
            counter += c[i];
        }
    }
    
  // output 
    cout << counter << endl;

}
