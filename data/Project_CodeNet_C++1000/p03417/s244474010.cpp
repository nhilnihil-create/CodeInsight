#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N,M;
    cin >> N >> M;
    if (N == 1 && M == 1){
        cout << 1 << endl;
    }
    else if (N == 1){
        if (M >= 3){
            cout << M - 2 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    else if (M == 1){
        if (N >= 3){
            cout << N - 2 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    else if (M == 2 || N == 2){
        cout << 0 << endl;
    }
    else{
        cout << (M - 2) * (N - 2) << endl;
    }
}

