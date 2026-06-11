#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
using namespace std;
using ll = long long;


int main()
{
    // input
    int m,k;
    cin >> m >> k;

    // solve
    if(k>=pow(2,m)) cout << "-1" << endl;
    else if(m==0){
        cout << "0 0" << endl;
    }
    else if(m==1){
        if(k==0) cout << "0 0 1 1" << endl;
        else if(k==1) cout << "-1" << endl;
    }
    else{
        for(int i=0; i<=pow(2,m)-1; i++){
            if(i==k) continue;
            cout << i << " " << endl;
        }
        cout << k << " " << endl;
        for(int i=pow(2,m)-1; i>=0; i--){
            if(i==k) continue;
            cout << i << " " << endl;
        }
        cout << k << " " << endl;
    }

    // output
    return 0;
}