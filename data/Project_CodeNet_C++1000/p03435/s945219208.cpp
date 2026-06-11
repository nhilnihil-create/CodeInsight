#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#include <bits/stdc++.h>
using namespace std;
int sum(vector<int> s){return accumulate(s.begin(),s.end(),0);}
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    int n = 3;
    vector<vector<int>> a(3,vector<int>(3));
    rep(i,3)rep(j,3)cin >> a[i][j];
    //rep(i,3)p(a[i]);
    vector<int> x(3);
    vector<int> y(3);
    rep(i,n)y[i] = a[0][i] - x[0];
    rep(i,n)x[i] = a[i][0] - y[0];
    bool flag = true;
    rep(i,n)rep(j,n){
        if(x[i] + y[j] != a[i][j]){
            flag = false;
        }
    }
    if(flag)cout << "Yes";
    else cout << "No";
}