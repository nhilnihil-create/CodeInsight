#include "./bits/stdc++.h"
using namespace std;

int n;

int main(){
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    sort(A,A+n);
    int sum=0;
    int max = A[n-1];
    for (int i=0;i<n-1;i++){
        sum+=A[i];
    }
    if(sum>max){
        cout <<"Yes"<<endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}