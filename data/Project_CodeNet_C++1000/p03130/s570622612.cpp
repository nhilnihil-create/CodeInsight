//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <complex>
#include <iomanip>
#include <queue>
#include <bitset>
//定数
#define MOD 1000000007
//マクロ
#define rep(i,n)    for(int (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

#define vsort(v) sort((v).begin(), (v).end());

typedef unsigned long long int ull;
typedef long long lint;

using namespace std;




int main(){
    int a[4], b[4];

    vector<int> num(5, 0);
    //入力
    rep(i,3) {
        int a, b;
        cin >> a >> b;
        num[a]++; num[b]++;
    }
    
    rep(i,4) if(num[i+1] >= 3) { cout << "NO" << endl; return 0; }
    cout << "YES" << endl;

    //cout << endl; 
    //rep(i,4) cout << num[i+1] << endl;

    

    return 0;
}