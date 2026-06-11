#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MAXN = 301;



int main(){
    int V[5] = {0, 0, 0, 0, 0};
    for(int i = 0; i < 3; i++){
        int a, b; cin >> a >> b;
        V[a]++;
        V[b]++;
    }
    for(int i = 1; i < 5; i++) if(V[i] == 3) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
}