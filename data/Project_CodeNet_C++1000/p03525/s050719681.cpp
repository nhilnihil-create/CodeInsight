#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int d[52];
    int t[13] {0};
    for(int i = 0; i < n; i++){
        cin >> d[i];
        t[d[i]]++;
    }
    d[n] = 0;
    t[0]++;
    if(t[0] > 1 || t[12] > 1){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i < 12; i++) if(t[i] > 2){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i < 12; i++) if(t[i] == 2 && (t[i - 1] == 1 || t[i + 1] == 1)){
        cout << 1 << endl;
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < (1 << (n + 1)); i++){
        int e[53];
        for(int j = 0; j <= n; j++){
            if((i >> j) & 1) e[j] = d[j];
            else e[j] = -d[j];
        }
        int l = 100;
        for(int j = 0; j <= n; j++) for(int k = j + 1; k <= n; k++){
            l = min(l, min(abs(e[j] - e[k]), 24 - abs(e[j] - e[k])));
        }
        ans = max(ans, l);
    }
    cout << ans << endl;
}