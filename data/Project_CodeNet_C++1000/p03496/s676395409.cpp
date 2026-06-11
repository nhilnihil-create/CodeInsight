#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define N_max 50

int main(){
    int N;
    cin >>N;
    int A[N_max];
    int abs_max=0,abs_ind=0;
    for(int i=0;i<N;i++){
        cin >> A[i];
        if(abs_max < abs(A[i])){
            abs_max=abs(A[i]);
            abs_ind=i;
        }
    }
    cout << 2*N-2 <<endl;
    for(int i=0;i<N;i++){
        if(i!=abs_ind) cout << abs_ind+1 << " " << i+1 << endl;
    }
    if(A[abs_ind] >=0){
        for(int i=1;i<N;i++) cout << i << " " << i+1 <<endl;
    }
    else{
        for(int i=N; 1< i ;i--) cout << i << " " <<i-1 <<endl;
    }
}