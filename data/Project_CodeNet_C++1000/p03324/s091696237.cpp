
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int d, n;
    cin >> d >> n;
    if(d==0 && n!=100){
        cout << n << endl;
    }
    else if(d==0 && n==100){
        cout << 101 << endl;
    }
    else if(d==1 && n!=100){
        cout << 100*n << endl;
    }
    else if(d==1 && n==100){
        cout << 10100 << endl;
    }
    else if(d==2 && n!=100){
        cout << 10000*n << endl;
    }
    else{
        cout << 1010000 << endl;
    }
}