#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, p[100], a, b, x[3] = {0};
    cin >> n >> a >> b;
    for(int i=0;i<n;++i) cin >> p[i];

    for(int i=0;i<n;++i){
        if(p[i] <= a) ++x[0];
        else if(p[i] <= b) ++x[1];
        else ++x[2];
    }
    cout << min({x[0], x[1], x[2]}) << endl;
    
    return 0;
}