#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;
using P = pair<int,int>;
using ll =long long;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

int main(){
    ll n,m;
    cin >> n >> m;
    if(n>2 && m>2){
        cout << (n-2)*(m-2) << endl;
    }else{
        if(n==1 && m==1){
            cout << 1 << endl;
        }
        else if(n==1){
            cout << m-2 << endl;
        }else if(m==1){
            cout << n-2 << endl;
        }else if(n==2 || m==2){
            cout << 0 << endl;
        }
    }
}