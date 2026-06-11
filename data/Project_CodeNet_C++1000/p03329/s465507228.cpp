#include <bits/stdc++.h>
using namespace std;



int main(){
    int N;
    cin >> N;
    vector<int> DP(N+1,-1);
    DP[0] = 0;
    for(int i = 0; i < N;i++){
        
        if(DP[i+1]!=-1)DP[i+1] = min(DP[i+1],DP[i] + 1);
        else DP[i+1] = DP[i] + 1;
        
        for(int j = 6; i < N;j*=6){
            if(i+j > N)break;
            if(DP[i+j]!=-1)DP[i+j] = min(DP[i+j],DP[i] + 1);
            else DP[i+j] = DP[i] + 1;
        }   
        
        for(int j = 9; i < N;j*=9){
            if(i+j > N)break;
            if(DP[i+j]!=-1)DP[i+j] = min(DP[i+j],DP[i] + 1);
            else DP[i+j] = DP[i] + 1;
        }  
        
    }
    int cont = 0;
    for(int i = 0; i < N;i++){
        cont = i;
        if(DP[N - cont]!=0)break;
    }
    
    //cout << DP[N]  << endl;
    //cout << cont << endl;
    cout << DP[N-cont] + cont << endl;
    
    
}