#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> t(100000), x(1000000), y(100000);
    for(int i=0; i<n; i++){
        cin >> t[i] >> x[i] >> y[i];
    }
    bool flg = true;
    if(t[0] != abs(x[0]) + abs(y[0])){
        flg = false;
        cout << "No" << endl;
        return 0;
    }
    for(int i=1; i<n; i++){
        if((t[i]-t[i-1] >= abs(x[i]-x[i-1])+abs(y[i]-y[i-1])) && (t[i]-t[i-1]-abs(x[i]-x[i-1])-abs(y[i]-y[i-1]))%2==0){
            flg =true;
        }else{flg =false; break;}
    }
    if(flg) cout << "Yes" << endl;
    else    cout << "No" << endl;
    return 0;
}