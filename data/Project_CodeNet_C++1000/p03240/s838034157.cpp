#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    int N;
    cin >> N;
    vector<ll> x(N),y(N),h(N);
    for(int i=0;i<N;i++){
        cin >> x[i] >> y[i] >> h[i];
    }

    ll correctX,correctY;
    for(int cx=0; cx<=100;cx++){
        for(int cy=0;cy<=100;cy++){
            ll H;
            for(int i=0;i<N;i++){
                if(h[i] !=0){
                    H = h[i] + abs(x[i]-cx) + abs(y[i]-cy);
                    break;
                }
            }
            bool ok = true;
            for(int i=0;i<N;i++){
                if(h[i] != max(H-abs(x[i]-cx)-abs(y[i]-cy),0LL)){
                    ok =false;
                }
            }
            if(ok){
                cout <<cx<< " " << cy <<" "<<H << endl;
                return 0;
            }
        }
    }

    return 0;
}