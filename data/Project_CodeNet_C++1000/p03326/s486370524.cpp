#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;


int main(){
    int N, M; cin >> N >> M;
    vector<ll> X(N), Y(N), Z(N); for(int i = 0; i < N; i++) cin >> X[i] >> Y[i] >> Z[i];
    ll Max = 0;
    for(int f1 = 0; f1 < 2; f1++){
        for(int f2 = 0; f2 < 2; f2++){
            for(int f3 = 0; f3 < 2; f3++){
                vector<ll> ABS(N);
                for(int i = 0; i < N; i++){
                    ll temp=0;
                    if(f1) temp += X[i]*(-1);
                    else temp += X[i];
                    if(f2) temp += Y[i]*(-1);
                    else temp += Y[i];
                    if(f3) temp += Z[i]*(-1);
                    else temp += Z[i];
                    ABS[i] = temp;
                }
                sort(ABS.rbegin(), ABS.rend());
                ll tempMax = 0;
                for(int i = 0; i < M; i++) tempMax += ABS[i];
                Max = max(Max, tempMax);
            }
        }
    }
    cout << Max << endl;


}