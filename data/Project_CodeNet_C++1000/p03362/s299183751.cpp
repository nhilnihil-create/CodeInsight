#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;

int main(){
    ll n ; cin >> n;
    vector<bool> a(55556,1);
    a.at(0)==0;
    a.at(1)==0;
    for(int i=2;i*i<=55555;i++){
        if(!a.at(i)) continue;
        ll x = a.at(i);
        for(int j=i+i;j<=55555;j+=i){
            a.at(j)=0;
        }
    }
    for(int i=2;i<=55555;i++){
        if(a.at(i) && i%5 == 1){
            if(n==1){
                cout << i <<endl;
                return 0;
            }
            cout << i << " ";
            n--;
        }
    }
    return 0;
}
