#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> L(N);
    for(int i = 0; i<N; i++){
        cin >> L[i]; 
    }
    int m =0;
    for(int i=0;i<N;i++){
        m = max(L[i],m);
    }
    int k = 0;
    for(int i=0;i<N;i++){
        k += L[i];
    } 
    
    if(k>2*m){
        cout << "Yes";
    }  
    else{
        cout << "No";
    }
}