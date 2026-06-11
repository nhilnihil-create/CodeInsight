#include "./bits/stdc++.h"
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    int c[M+1];

    for(int i=1;i<=M;i++){
        c[i]=0;
    }

    int k,v;
    for(int i=0;i<N;i++){
        cin >> k;
        for(int j=0;j<k;j++){
            cin >> v;
            c[v]++;
        }
    }

    int ans=0;
    for(int i=1;i<=M;i++){
        if(c[i]==N) ans++;
    }
    cout << ans << endl;
    return 0;
}