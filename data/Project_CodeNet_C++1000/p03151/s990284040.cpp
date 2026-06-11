#include <bits/stdc++.h>
#include <climits>
#include <sstream>
using namespace std;

int main() {
    
    int N;
    cin >> N;
    vector<long long> A(N,0);
    vector<long long> B(N,0);
    
    for(int i = 0; i < N;i++)cin >> A[i];
    for(int i = 0; i < N;i++)cin >> B[i];
    
    
    vector<long long> C;
    long long D = 0;
    long long Csum = 0;
    int Dcont = 0;
    for(int i = 0; i < N;i++){
        
        if(A[i]-B[i]>0){
            C.push_back(A[i]-B[i]);
            Csum += A[i]-B[i];
        }else if(A[i] - B[i] < 0){
            D+=(A[i]-B[i]);
            Dcont++;
        }
    }
    
    if(D==0){
        cout << 0 << endl;
        return 0;
    }
    
    if(Csum + D <0){
        cout << -1 << endl;
        return 0;
    }
    
    
    sort(C.begin(),C.end(),greater<int>());
    
    int ans = 0;
    int index = 0;
    //cout << D << endl;
    while(D<0){
        //cout << D <<" "<< endl;  
        D+=C[index];
        index++;
        
        
    }
    
    ans = index + Dcont;
    cout << ans << endl;
    //for(auto u:C)cout << u << " ";
    //cout << endl;

}