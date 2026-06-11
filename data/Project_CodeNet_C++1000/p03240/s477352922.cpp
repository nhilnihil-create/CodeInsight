#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<int> x(N),y(N),h(N);
    rep(i,N){
        cin >> x[i] >> y[i] >> h[i];
    }
    for(int cx=0;cx<=100;cx++){
        for(int cy=0;cy<=100;cy++){
            int H;
            for(int i=0;i<N;i++){
                if(h[i]!=0){
                    H = h[i] + abs(x[i]-cx)+abs(y[i]-cy);
                }
            }
            bool flg = true;
            for(int i=0;i<N;i++){
                if(H-abs(x[i]-cx)-abs(y[i]-cy)<=0&&h[i]==0) continue;
                if(h[i] + abs(x[i]-cx)+abs(y[i]-cy)!=H){
                    flg = false;
                }
            }
            if(flg){
                cout << cx << " " << cy << " " << H << endl;
                return 0;
            }
        }
    }
    cout << "ERROR" << endl;
    return 0;
}