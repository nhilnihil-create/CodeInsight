#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <deque>
using namespace std;

long bigger(long a, long b){
    if(a >= b){
      return a;
    }else{
      return b;
    }
}

int main() {
    //input
    long k,a,b;cin >> k >> a >> b;
   
    //compute
    long ans;
    ans = 1 + k + bigger(0 , bigger(0 , (1+ k -a)/2) * (b - a - 2));

    //output
    cout << ans << endl;
}