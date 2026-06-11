#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;

int main() {
    int x,y; cin >> x >> y;
    string s; cin >> s;
    int a[s.length()+1]; int sum = 0;
    for(int i = 0;i < s.length()+1;i++){
        a[i] = 0;
    }
    for(int i = 0;i < s.length()+1;i++){
        if(s[i] == 'A' && s[i+1] == 'C'){
            sum ++;
            a[i+1] = sum;
        }else{
            a[i+1] = sum;
        }
    }
    
    for(int i = 0;i < y;i++){
        int d,f; cin >> d >> f;
        cout << a[f-1]-a[d-1] << endl;
    }
}

