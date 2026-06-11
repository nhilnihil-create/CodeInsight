/**
*    author:  Taichicchi
*    created: 10.09.2020 20:15:20
**/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int cnt = B / A;

    int ans;

    if(cnt > C){
        ans = C;
    }else{
        ans = cnt;
    }

    cout << ans << endl;



    return 0;
}