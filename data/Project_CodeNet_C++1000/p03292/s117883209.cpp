#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int A[3],ans=0,swap;
    cin >> A[0] >> A[1] >> A[2];
    sort(A,A+3);
    ans+=A[1]-A[0];
    ans+=A[2]-A[1];
    cout << ans;
}