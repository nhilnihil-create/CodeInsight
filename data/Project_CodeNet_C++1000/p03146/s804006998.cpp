#include<bits/stdc++.h>
using namespace std;

int f(int n){
    if(n % 2 == 0) return n/2;
    else return 3*n + 1;
}

int main(){
    int s, a, ans = 1;
    set<int> S;
    cin >> s;
    a = s;
    S.insert(a);
    while(true){
        ++ans;
        a = f(a);
        if(S.find(a) != S.end()) break;
        else  S.insert(a);
    }
    cout << ans << endl;
    return 0;
}