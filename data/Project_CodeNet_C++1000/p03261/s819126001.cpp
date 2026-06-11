#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int i;
    for(i = 1; i < n; i++){
        int j;
        for(j = 0; j < i; j++){
            if(v[i] == v[j]) break;
        }
        if(i != j) break;
        if(v[i][0] != v[i-1][v[i-1].size()-1]) break;
    }
    if(i == n) cout << "Yes" << endl;
    else cout << "No" << endl;
}