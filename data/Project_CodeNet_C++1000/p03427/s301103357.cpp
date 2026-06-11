#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    ll n;
    int s = 0; 
    cin >> n;
    int cnt = 1;
    while(n > 9){
        if(n%10 != 9) s = 1;
        n /= 10;
        cnt++;
    }
    if(s == 0) cout << n + 9*(cnt-1) << endl;
    else{
        cout << n + 9*(cnt-1)-1 << endl;
    }
}