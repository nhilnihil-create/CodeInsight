#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main(){
    int N;
    cin >> N;
    vector<LL> X(N);
    vector<LL> X2(N);
    REP(i,N){
        cin>>X[i];
        X2[i]=X[i];
    }

    int n_1 = (N/2);

    sort(X.begin(), X.end());
    LL val1 = X[n_1];
    LL val2 = X[n_1-1];
    
    REP(i,N){
        if(X2[i]<val1){
            cout << val1 << endl;
        }else{
            cout << val2 << endl;
        }
    }
    return 0;


}