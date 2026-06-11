#include <bits/stdc++.h>
using namespace std ;
#define An setprecision(16) 
int main(){
    int A[3];
    cin >> A[0]>>A[1]>>A[2];
    sort(A,A+3);
    int count =0;
    while(A[1]<A[2]){
        A[0]++;A[1]++;count++;
    }
    while(A[0]<A[1]){
        A[0]+=2;count++;
    }
    if(A[0]==A[1]){
        cout << count << endl;
    }else{
        count++;
        cout << count <<endl;
    }

}