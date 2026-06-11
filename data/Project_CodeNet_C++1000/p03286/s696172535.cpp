#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

const int nmax=3010; 
ll N;
int bit[nmax];

void solve(){
    ll n;
    int i,j;
    n = N;  
    rep(i,nmax) bit[i]=0;
    i = 0;
    while(1){
        if (n - ((ll)(n/2)*2 ) != 0){
            // cout << "bit " << n << " " << i << " set 1" << endl;
            bit[i]=1;
        } 
        n = (ll)((n - bit[i]) /  (-2) );
        if (n ==  0){ break; }
        i = i + 1;
    }
    for(int j=i; j>=0; j--){
        cout << bit[j];
    }
    cout << endl;
}

int main() {
    int i,j; 
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N ;
    // cout << N <<  endl;
    solve();
    
}
