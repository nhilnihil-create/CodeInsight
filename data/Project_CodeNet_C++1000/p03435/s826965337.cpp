#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    vector<vector<int>> cij(3,vector<int>(3));
    rep(i,3){
        cin>> cij[i][0] >> cij[i][1] >> cij[i][2];
    }

    vector<int> row_sum(3,0);
    vector<int> col_sum(3,0);
    for(int k:{0, 1, 2}){
        for(int j:{0, 1, 2}){
            row_sum[k] += cij[k][j];
            col_sum[j] += cij[k][j];
        }
    }

    int sum1 = row_sum[0] - row_sum[1];
    int sum2 = row_sum[1] - row_sum[2];
    int sum3 = row_sum[2] - row_sum[0];

    if(sum1%3!=0 || sum2%3 !=0|| sum3%3 !=0){
        cout << "No" << endl;
        return 0;
    }

    sum1 = col_sum[0] - col_sum[1];
    sum2 = col_sum[1] - col_sum[2];
    sum3 = col_sum[2] - col_sum[0];

    if(sum1%3!=0 || sum2%3 !=0|| sum3%3 !=0){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;
}