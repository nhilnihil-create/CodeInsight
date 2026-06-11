#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){
    int a, b, x;
    cin >> a >> b >> x;
    if(a > x){
        cout << "NO" << endl;
    }else if(a+b >= x){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}