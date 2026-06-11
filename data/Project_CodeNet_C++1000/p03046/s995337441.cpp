#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(20);
    int M,K;
    cin >> M >> K;
    int mx = (1<<M) - 1;
    if(M==1&&K==0){
        cout << "0 0 1 1" << endl;
        return 0;
    }
    if(M==1&&K==1){
        cout << -1 << endl;
        return 0;
    }
    if(K>mx){
        cout << -1 << endl;
        return 0;
    }
    for(int i=0;i<=mx;i++){
        if(i==K)continue;
        cout << i << " ";
    }
    cout << K <<" ";
    for(int i=mx;i>=0;i--){
        if(i==K)continue;
        cout << i << " ";
    }
    cout << K << endl;
}