#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> pow_time(19,0);
    for(int i=1; i<=n; i++){
        int time=0;
        int calc=i;
        while(calc <k){
            calc *= 2;
            time++;
        }
        pow_time.at(time)++;
    }
    ll ans=0;
    ll down = pow(2,18);
    ll two_pow=1;
    for(int i=18; i>=0; i--){
        ans += pow_time.at(i) * two_pow;
        two_pow *= 2;
    }
    ll div = down*n;
    cout << fixed << setprecision(10) << (double) ans/div << endl;
}
