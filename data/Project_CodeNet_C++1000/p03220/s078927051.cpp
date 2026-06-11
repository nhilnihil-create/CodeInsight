#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,t,a;
    cin >> n >> t >> a;
    vector<int> h(n);
    for(int i=0; i<n; i++){
        cin >> h.at(i);
    }
    double temp = 0;
    double comptemp = DBL_MAX;
    int ans = 0;
    for(int i=1; i<=n; i++){
        temp = t - h.at(i-1) * 0.006;
        temp = abs(a - temp);
        if(comptemp > temp){
            comptemp = temp;
            ans = i;
        }
    }
    cout << ans << endl;
}