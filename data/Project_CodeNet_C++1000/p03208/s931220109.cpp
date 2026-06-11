#include "./bits/stdc++.h"
using namespace std;
using ll = long long;

int main(){
    int N,K,h;
    cin >> N >> K;
    ll v[N];
    for(int i=0;i<N;i++){
        cin >> v[i];
    }
    int INFTY = 100000000000;
    int min = INFTY;
    sort(v,v+N);
    for(int i=0;i<=N-K;i++){
        if(min > v[i+K-1] - v[i]){
            min = v[i+K-1] - v[i];
        }
    }

    cout << min << endl;

    return 0;
}