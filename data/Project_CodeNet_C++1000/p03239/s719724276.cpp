#include "./bits/stdc++.h"

using namespace std;

int main(){
    int N,T;
    cin >> N >> T;
    
    vector<int> C(N);
    vector<int> T_vec(N);

    for (int i=0;i<N;i++){
        cin >> C[i] >> T_vec[i];
    }

    int min=1000000;
    int ans=-1;
    for (int i=0;i<N;i++){
        if(T>=T_vec[i] && min >= C[i]){
            min=C[i];
            ans=i;
        }
    }
   
    if(ans==-1){
        cout << "TLE" << endl;
    }else{
        cout << C[ans] << endl;
    }
    
    return 0;
}