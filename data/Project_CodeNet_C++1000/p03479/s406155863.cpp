#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
    
int main(){
    long long x,y;
    cin >> x >> y;
    long long cur = x;
    int cnt = 1;
    while(2*x <= y){
        x = 2*x;
        cnt ++;
    }
    cout << cnt << endl;
}