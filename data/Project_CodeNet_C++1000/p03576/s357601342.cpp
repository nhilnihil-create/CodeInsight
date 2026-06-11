#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll N,K;
ll x[50];
ll y[50];
ll MIN_S = 5e18;

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> x[i] >> y[i];
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            for(int a=0;a<N;a++){
                for(int b=a+1;b<N;b++){
                    ll minx = min(x[i],x[j]);
                    ll maxx = max(x[i],x[j]);
                    ll miny = min(y[a],y[b]);
                    ll maxy = max(y[a],y[b]);
                    int count = 0;
                    for(int k=0;k<N;k++){
                        if(x[k] >= minx && x[k] <= maxx && y[k] >= miny && y[k] <= maxy){
                            count++;
                        }
                    }
                    if(count < K) continue;
                    ll s = (maxx-minx)*(maxy-miny);
                    MIN_S = min(s,MIN_S);
                }
            }
        }
    }
    cout << MIN_S << endl;
    return 0;
}