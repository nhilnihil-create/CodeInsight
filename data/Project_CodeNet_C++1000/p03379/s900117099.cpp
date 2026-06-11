#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<int> X(N),X2(N);
    rep(i,N){
        cin >> X[i];
        X2[i] = X[i];
    }
    sort(X.begin(),X.end());
    for(int i=0;i<N;i++){
        if(X2[i]<X[N/2]){
            cout << X[N/2] << endl;
        }else{
            cout << X[N/2-1] << endl;
        }
    }
    return 0;
}