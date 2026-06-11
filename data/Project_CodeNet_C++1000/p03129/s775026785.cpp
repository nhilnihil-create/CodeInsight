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
    int N, K;

    //入力
    cin >> N >> K;
    int count;
    if(N%2 == 0) {
        count = N/2;
    } else {
        count = N/2+1;
    }

    if(count >= K) cout << "YES" << endl;
    else          cout << "NO"  << endl;

    return 0;
}