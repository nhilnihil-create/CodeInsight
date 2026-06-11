#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,kesu;
    cin >> N;
    vector<int> b(N),ans(N);
    for(int i=0;i<N;i++){
        cin >> b[i];
    }
    for(int i=0;i<N;i++){
        kesu = -1;
        for(int j=0;j<N-i;j++){
            if(b[j]==j+1){
                kesu = j;
            }
        }
        if(kesu==-1){
            break;
        }
        b.erase(b.begin()+kesu);
        ans[i] = kesu+1;
    }


    if(!b.empty()){
        cout << -1 << endl;
    }else{
        for(int i=0;i<N;i++){
            cout << ans[N-1-i] << endl;
        }
    }
}