#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<string> w(n);
    map<string, int> z;
    for (int i = 0; i < n; i++){cin >> w[i];z[w[i]] = 0;}
    z[w[0]] = 1;
    for (int i = 0; i < n-1; i++){
        if (z[w[i+1]] || w[i][w[i].size()-1] != w[i+1][0]){
            cout << "No" << endl;
            return 0;
        }else{
            z[w[i+1]] = 1;
        }
    }
    cout << "Yes" << endl;
    return 0;
}