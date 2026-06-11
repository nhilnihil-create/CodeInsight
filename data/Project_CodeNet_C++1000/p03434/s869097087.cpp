
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;    
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n;
int a[110];
int alice = 0;        
int bob = 0;
    int main() {
    //nを入力
    cin >> n;
    //aを配列に入れ込む作業をn回行なう
    rep(i, n){
        cin >> a[i];
    }
    sort(a, a+n, greater<int>());
    rep(i,n){
        if(i %2 ==0){
            alice += a[i];
        }else{
            bob += a[i];
        }
    }
    cout << alice - bob << endl;
}