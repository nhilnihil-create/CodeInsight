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
    int n, m, k, aux, rta = 0;
    cin >> n >> m;
    bool lista[n][m];
    memset(lista, 0,  sizeof(lista));
    for(int i = 0; i < n; i++){
        cin >> k;
        for(int j = 0; j < k; j++){
            cin >> aux;
            lista[i][aux-1] = true;
        }
    }
    for(int i = 0; i < m; i++){
        aux = 0;
        for(int j = 0; j < n; j++){
            if(lista[j][i]) aux++;
        }
        if(aux == n) rta++;
    }
    cout << rta << endl;
    return 0;
}

