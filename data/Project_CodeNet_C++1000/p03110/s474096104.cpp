#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long double ans = 0;
    cin >> n;
    vector<pair<string, long double>> data(n);
    for (int i = 0; i < n; i++){
        cin >> data.at(i).second >> data.at(i).first;
    }
    for (int i = 0; i < n; i++){
        if(data.at(i).first == "JPY"){
            ans += data.at(i).second;
        }else{
            ans += data.at(i).second * 380000.0;
        }
    }
    cout << fixed << setprecision(100) << ans << endl;
}