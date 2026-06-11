#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    cout << 100 << ' ' << 100 << endl;
    char g[100][100];
    for(int i=0; i<50; i++){
        for(int j=0; j<100; j++){
            g[i][j] = '.';
            g[i+50][j] = '#';
        }
    }
    for(int i=0; i<b-1; i++){
        g[(i/50)*2][(i%50)*2] = '#';
    }
    for(int i=0; i<a-1; i++){
        g[(i/50)*2 + 51][(i%50)*2] = '.';
    }
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            cout << g[i][j];
        }
        cout << endl;
    }
    return 0;
}
