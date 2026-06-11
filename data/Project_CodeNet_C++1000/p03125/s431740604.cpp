
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int a, b;
    cin >> a >> b;
    if(b%a==0){
        cout << a+b << endl;
        return 0;
    }
    else{
        cout << b-a << endl;
        return 0;
    }
}