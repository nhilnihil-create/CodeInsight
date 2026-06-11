#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <deque>
using namespace std;
using P = pair<int,int>;
typedef long long int ll;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)

int main(){
    ll a,b,k; cin >> a >> b >> k;
    rep(i,k){
        if(i%2==0){
            if(a%2!=0){
                a--;
            }
            a = a/2;
            b += a;
        }else{
            if(b%2!=0){
                b--;
            }
            b = b/2;
            a += b;
        }
    }
    cout << a <<endl;
    cout << b << endl;    
    return 0;
}


