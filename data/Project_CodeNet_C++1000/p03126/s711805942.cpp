#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n,m;
    cin >> n >> m;
    vector<int> ans(m,0);
    int k;
    for(int j=0; j<n; j++){
    cin >> k;
    vector<int> a(k);
        for(int i=0; i<k; i++){
            cin >> a.at(i);
            ans.at(a.at(i)-1) += 1;
        }
    }
    int solve = 0;
    for(int i:ans) {
        if(i == n){
            solve += 1;
        }
    }
    cout << solve << endl;
}