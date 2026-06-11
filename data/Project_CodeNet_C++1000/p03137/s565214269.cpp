#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i,x) for(int i = 1; i <= x; i++)
#define SORT(x) sort(x.begin(),x.end())
#define dupl(s) s.erase(unique(s.begin(), s.end()), s.end());//重複取り除き
#include <bits/stdc++.h>
using namespace std;
int sum(vector<int> s){return accumulate(s.begin(),s.end(),0);}
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    vector<int> y;
    rep(i,m)cin >> x[i];
    sort(x.begin(),x.end());
    rep(i,m-1){
        int dir = abs(x[i+1] - x[i]);
        y.push_back(dir);
    }
    int sum = accumulate(y.begin(),y.end(),0);
    sort(y.begin(),y.end(),greater<int>());
    for(int i = 0; i < min(n-1,(int)y.size()); i++){
        sum -= y[i];
    }
    cout << sum;
}