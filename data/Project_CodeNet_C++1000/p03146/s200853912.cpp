#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<map>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int Collatz(int inn){
    if(inn%2==0){
        return inn/2;
    }
    else{
        return 3*inn+1;
    }
}

int main(){
    int ans=0;
    int n;
    cin>>n;
    vector<int> a(1000005,0);
    a[n-1]=1;
    for(int i=1;;i++){
        a[Collatz(n)-1]++;
        if(a[Collatz(n)-1]==2){
            ans=i+1;
            break;
        }
        n=Collatz(n);
    }
    cout<<ans<<endl;
}