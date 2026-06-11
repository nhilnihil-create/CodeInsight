#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;
    int m = 3500;
    for(int i = 1; i < m; i++){
        for(int j = i; j < m; j++){
            if(4*i*j-n*j-n*i == 0) continue;
            double t = (double)n*i*j/(4*i*j-n*j-n*i);
            if(floor(t) == t && t > 0){
                cout << i << " " << j << " " << (int)t << endl;
                //int k = (int)t;
                //cout << n*(j*k+i*k+i*j) << " " << 4*i*j*k << endl;
                return 0;
            }
        }
    }
    return 0;
}