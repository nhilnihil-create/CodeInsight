#include <bits/stdc++.h>
using namespace std;

int N, m, k, toll[101], a, tot1=0, tot2=0;

int main () {
    cin >> N >> m >> k;
    for (int i=1; i<=m; i++) {
        cin >> a;
        toll[a]=1;
    }
    for(int i=1; i<=k; i++){
        tot1 += toll[i];
    }
    for(int i=k; i<=N; i++){
        tot2 += toll[i];
    }
    if (tot2<tot1){
        cout << tot2 << endl;
    }
    else {
        cout << tot1 << endl;
    }
}