
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    char b;
    cin >> b;
    if(b=='A'){
        cout << 'T' << endl;
    }
    else if(b=='T'){
        cout << 'A' << endl;
    }
    else if(b=='G'){
        cout << 'C' << endl;
    }
    else{
        cout << 'G' << endl;
    }
}