#include <bits/stdc++.h>
using namespace std;



int wa(int c){ //各位の和
    int cnt = 0;
    while(true){
        if(c / 10 == 0){
            cnt += c % 10;
            break;
        }
        cnt += c % 10;
        c /= 10;
    }
    return cnt;
}

int number(int n){
    vector<int> plus(n);
    for(int i=0; i<n; i++){
        int a = (i+1);
        int b = n - a;
        int c = wa(a);
        int d = wa(b);
        plus.at(i) = c + d;
    }

    sort(plus.begin(), plus.end());

    return plus.at(0);
    /*
    a = 1;
    int a_wa = wa(a);
    b = n - 1;
    int b_wa = wa(b);
    return a_wa + b_wa;
    */
}

int main(){ // 各位の和を配列に入れてソートすれば答えが出そう
    int N;
    cin >> N;
    int ans = number(N);
    if(ans == 1) ans *= 10;

    cout << ans << endl;
}