#include<bits/stdc++.h>
using namespace std;


int main(){

    int res = 0;
    int sum=0;
    int n, m, c;
    cin >> n >> m >> c;

    int A[m];
    int B[m];
    for(int i=0; i<m; i++){
        cin >> B[i];
    }
    
    for(int i=0; i<n; i++){
        sum = c;
        for(int j=0; j<m; j++){
            cin >> A[j];
            sum += A[j]*B[j]; 
        }
        if(sum > 0)
            res++;
    }

    cout << res << endl;

}