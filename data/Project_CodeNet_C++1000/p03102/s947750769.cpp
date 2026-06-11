#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b(m);
    int a[n][m];

    for(int i=0; i<m; ++i)
        cin >> b[i];

    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            cin >> a[i][j];

    int count = 0;

    for(int i=0; i<n; ++i){
        int s = 0;
        for(int j=0; j<m; ++j){
            s += a[i][j] * b[j];
        }
        s += c;

        if(s > 0)
            count++;
    }
    cout << count;
}
