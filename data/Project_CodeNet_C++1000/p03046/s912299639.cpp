#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ll M, K;
    cin >> M >> K;

    if((1 << M) <= K){
        cout << "-1" << endl;
        return 0;
    }

    if(M==1){
        if(K==0) cout << "0 0 1 1" <<endl;
        else     cout << "-1" << endl;
        return 0;
    }

    for(ll bit=0; bit < (1 << M); bit++){
        if(bit == K) continue;
        cout << bit << " ";
    }
    cout << K << " ";
    for(ll bit = (1 << M) - 1; bit >= 0; bit--){
        if(bit == K) continue;
        cout << bit << " ";
    }
    cout << K << endl;
    return 0;

}