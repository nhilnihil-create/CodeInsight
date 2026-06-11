#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<double> x(n);
    vector<string> u(n); 
    int jmoney = 0;
    double bmoney = 0;
    for(int i=0; i<n; i++){
        cin >> x.at(i);
        cin >> u.at(i);
        if(u.at(i) == "BTC"){
            bmoney += x.at(i)*380000;
        }
        else{
            jmoney += x.at(i);
        }
    }
    cout << bmoney+jmoney << endl;
}