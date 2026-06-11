#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;

int main(){
    long double n, m, d; cin >> n >> m >> d;
    if(m == 1){cout << 0;}
    else{
    if(d>0){
    cout << setprecision(10) << 2*(n-d)*(m-1)/(n*n);
    }
    else{
    cout << setprecision(10) << (n-d)*(m-1)/(n*n);
    }
    }
}