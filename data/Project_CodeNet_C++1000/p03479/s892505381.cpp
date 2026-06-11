 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 const int INF = 2147483647;

int main() {
    ll x,y;
    cin >> x >> y;
    ll now=x;
    int cnt=0;
    while(now<=y){
        now*=2; 
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}