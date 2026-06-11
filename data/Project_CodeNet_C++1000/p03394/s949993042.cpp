#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int NN = N;
    if(N == 3){
        cout << "2 5 63" << endl;
        return 0;
    }
    
    N -= 4;
    vector<int> ans = {2, 4, 3, 9};
    for(int v=8; v<30000; v+=6){
        if(N >= 2){
            N -= 2;
            ans.push_back(v);
            ans.push_back(v+2);
        }
    }
    for(int v=15; v<30000; v+=12){
        if(N >= 2){
            N -= 2;
            ans.push_back(v);
            ans.push_back(v+6);
        }
    }
    for(int v=6; v<=30000; v+=6){
        if(N >= 1){
            N--;
            ans.push_back(v);
        }
    }
    for(int i=0; i<NN; i++) cout << ans[i] << " \n"[i==NN-1];
}