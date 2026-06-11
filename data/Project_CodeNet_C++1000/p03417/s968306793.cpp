
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    ll n, m;
    cin >> n >> m;
    if(n>2 && m>2){
        cout << (n-2)*(m-2) << endl;
    }
    else if(n==1 && m==1){
        cout << 1 << endl;
    }
    else if(n==1 && m>2){
        cout << m-2 << endl;
    }
    else if(m==1 && n>2){
        cout << n-2 << endl;
    }
    else cout << 0 << endl;
}