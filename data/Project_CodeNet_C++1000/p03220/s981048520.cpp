#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n;
    double t,a;
    cin>>n>>t>>a;
    
    double mindif= 200000, diff;
    int h, mini;
    rep(i,n){
        cin>>h;
        diff = abs(a-(t-0.006*h));
        
        if(diff<mindif){
            mini = i+1;
            mindif = diff;
        }
    }
    
    cout << mini << endl;
    return 0;
}