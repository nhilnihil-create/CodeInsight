#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<long long> A(N),B(N);
    vector<pair<long long,long long>> C;
    for(int i = 0; i < N;i++){
        cin >> A[i] >> B[i];
        C.push_back(make_pair(A[i]+B[i],i));
    }
    
    sort(C.begin(),C.end());
    reverse(C.begin(),C.end());
    
    long long tSum = 0,aSum = 0;
    for(int i = 0; i < N;i++){
       int index = C[i].second;
       if(i % 2 == 0){
           tSum += A[index];
       }else{
           aSum += B[index];
       }
    }
    cout << tSum - aSum << endl;
    
    
}
