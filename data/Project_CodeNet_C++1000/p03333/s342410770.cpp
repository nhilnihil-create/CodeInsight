// I saw tourist's code.

#include<bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i];
    }
    x.push_back(0);
    y.push_back(0);
    sort(x.rbegin(), x.rend());
    sort(y.begin(), y.end());

    long long ans = 0;
    for(int i = 0; i < N; i++){
        if(x[i] > y[i]){
            ans += 2 * (x[i] - y[i]);
        }
    }

    cout << ans << endl;
}
