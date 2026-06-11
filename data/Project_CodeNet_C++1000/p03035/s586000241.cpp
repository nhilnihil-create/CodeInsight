
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int a,b;
    cin >> a >> b;
    if(a>=13){
        cout << b << endl;
        return 0;
    }
    else if(a>=6 && a<=12){
        cout << b/2 << endl;
    }
    else cout << 0 << endl;
}