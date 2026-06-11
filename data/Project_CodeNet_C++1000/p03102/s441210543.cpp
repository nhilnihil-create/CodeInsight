#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define ft first
#define sd second
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char,char> pcc;
typedef pair<long long,long long> pll;

int main() {
    fastIO;
    int n, m, c;
    ll rta = 0, aux;
    cin >> n >> m >> c;
    ll b[m], a[n][m];
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        aux = 0;
        for(int j = 0; j < m; j++){
            aux += b[j]*a[i][j];
        }
        aux += c;
        if(aux > 0) rta++;
    }
    cout << rta << endl;
    return 0;
}

