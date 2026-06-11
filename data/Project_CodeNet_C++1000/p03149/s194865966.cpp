#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<int,int>;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    bool n[4] = {false};
    if(a == 1 || b == 1 || c == 1 || d == 1){
        n[0] = true; 
    }
    if(a == 9 || b == 9 || c == 9 || d == 9){
        n[1] = true; 
    }
    if(a == 7 || b == 7 || c == 7 || d == 7){
        n[2] = true; 
    }
    if(a == 4 || b == 4 || c == 4 || d == 4){
        n[3] = true; 
    }

    if(n[0] && n[1] && n[2] && n[3]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
