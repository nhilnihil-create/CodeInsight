#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>   // popen, pclose, fgets
#include <cstdlib> 
using namespace std;
#define rep0(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vvi = vector<vi>; // intの2次元の型に vvi という別名をつける
using vvvi = vector<vvi>;
using ll = long long; //10e19までいける
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll =vector<vvll>;
const double PI=3.14159265358979323846;
//小数点以下を指定したい時　　→→→→  cout << fixed << setprecision()<<答え<<endl;
//int→string
//string→int   int num = atoi(numStr.c_str());

int main() {
    int n,m;cin>>n>>m;
    vi k(n),dish(m);
    rep0(i,n){
        cin>>k[i];
        vi A(k[i]);
        rep0(j,k[i]){
            cin>>A[j];
            dish[A[j]-1]++;
        }
    }
    int ans=0;
    rep0(i,m){
        if(dish[i]==n){
            ans++;
        }
    }
    cout<<ans<<endl;
}