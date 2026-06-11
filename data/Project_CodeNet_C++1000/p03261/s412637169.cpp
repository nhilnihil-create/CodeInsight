#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
    int n; cin >> n;
    vector<string> w(n);
    rep(i,n) 
        cin >> w[i];

    bool flg = true;
    for(int i=0; i<n-1; i++){
        if(w[i].back() != w[i+1].front()){
            flg = false; break;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(w[i] == w[j]){
                flg = false; break;
            }
        }
    }
    
    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;

}