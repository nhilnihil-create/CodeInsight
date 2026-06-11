#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> b(100), a;
    for(int i=0; i<n; i++){
        cin >> b[i];
    }

    bool flg = true;
    int cnt = n;
    while(true){
        flg = false;
        for(int i=n-1; i>=0; i--){
            if(b[i] == i+1){
                a.push_back(b[i]);
                b.erase(b.begin()+i);
                n--;
                flg = true;
                break;
            }
        }
        if(n == 0){
            flg = true; break;
        }
        if(!flg){
            cout << -1 << endl;
            return 0;
            // break;
        }
    }
    if(flg){
        for(int i=cnt-1; i>=0; i--){
            cout << a[i] << endl;
        }
    }else{
        cout << -1 << endl;
    }
    return 0;
}