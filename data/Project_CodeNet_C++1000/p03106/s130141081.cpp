#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    int a,b,k;
    cin >> a >> b >> k;
    vector<int> d;
    int cnt = 0;
    //cout << a << b << k;
    for(int i = 1;i <= 100;i++){
        if(a % i == 0 && b % i == 0){
            cnt++;
            d.push_back(i);}
    }
    rep(i,d.size()){
        if(i == d.size()-k)cout << d[i];
    }
}