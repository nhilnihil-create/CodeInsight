#include<iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
    int A[2][n];
    int sum=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin >> A[i][j];

            if(i==1){
                sum += A[i][j];
            }
        }
    }

    int ans= A[0][0] + sum;
    sum = ans;
    for(int i=1;i<n;i++){
        sum += A[0][i] - A[1][i-1];
        ans = max(ans,sum);
    }
    cout << ans << endl;
}