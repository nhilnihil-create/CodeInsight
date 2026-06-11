#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N,M,wa=0,hako=0,las=0;
    cin >> N >> M;

    vector<vector<long long>> A(N,vector<long long>(2));
    
    for(int i = 0;i < N;i++){
        cin >> A.at(i).at(0) >> A.at(i).at(1);
    }

    sort(A.begin(),A.end());

    for(int i = 0;i < N;i++){
         if((hako + A.at(i).at(1)) <= M){              
             hako += A.at(i).at(1);
             wa += A.at(i).at(0) * A.at(i).at(1); 
         }else if((hako + A.at(i).at(1)) > M && hako < M){
             las = M - hako;
             wa += A.at(i).at(0) * las; 
             break;
         }
    }
    cout << wa << endl;

}