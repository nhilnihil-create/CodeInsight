#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long int in = 1000000001;
    long long int ax = 0;
    long long int now;
    for (int i = 0; i < n; i++){
        cin >> now;
        in = min(in, now);
        ax = max(ax, now);
    }
    cout << ax - in << endl;
    return 0;
}