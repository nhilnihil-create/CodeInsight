#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> x(N,0);
    vector<ll> y(N,0);
    vector<ll> h(N,0);
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i] >> h[i];
    }

    ll C_x;
    ll C_y;
    ll H = 0;



    //h[i] = max(H - abs(x[i] - C_x) - abs(y[i] - C_y), 0LL);
    for(int j = 0; j < 101; j++){
        for(int k = 0; k < 101; k++){
            H = -1;
            ll n = 0;
            while(H < 1) {
                if(h[n] > 0) H = abs(x[n]-j) + abs(y[n]-k) + h[n];
                n++;
            }
            for(int i = 0; i < N; i++){
                if(max(H - abs(x[i]-j) - abs(y[i]-k) , 0LL) != h[i]) break;
                if(i == N-1) {
                    cout << j << " " << k << " " << H << endl;
                return 0;
                }
            }
        }
    }
}   
