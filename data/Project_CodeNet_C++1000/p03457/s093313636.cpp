#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    int t[N+1];
    int x[N+1];
    int y[N+1];
    t[0] = x[0] = y[0] = 0;
    for(int i = 0; i < N; i++) {
        cin >> t[i+1] >> x[i+1] >> y[i+1];
    }

    bool flag = true;

    for(int i = 0; i < N; i++){
        int dt = t[i+1] - t[i];
        int dist = abs(x[i+1]-x[i]) + abs(y[i+1]-y[i]);

        if(dist > dt) flag = false;
        if(dt%2 != dist%2) flag = false;
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}