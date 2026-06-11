#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastIO;
    int N;
    cin >> N;
    vector<long long> x(N+1,0);
    vector<long long> y(N+1,0);
    vector<long long> t(N+1,0);
    for(int i=1; i<N+1; i++){
        cin >> t[i] >> x[i] >> y[i];
        int dt = abs(t[i]-t[i-1]);
        int dx = abs(x[i]-x[i-1]);
        int dy = abs(y[i]-y[i-1]);
        if(dt%2!=(dy+dx)%2 || dt < dx+dy){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
