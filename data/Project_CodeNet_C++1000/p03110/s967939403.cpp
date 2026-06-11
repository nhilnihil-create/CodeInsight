#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
using G=vector<vector<int>>;

int main(){
    int n;
    cin >> n;
    double ans=0.0;
    vector<double> x(n);
    vector<string> u(n);
    rp(i,n) cin >> x.at(i) >> u.at(i);
    rp(i,n){
        if(u.at(i)=="JPY"){
            ans+=x.at(i);
        }
        else{
            double yen;
            yen = x.at(i)*380000.000;
            ans += yen;
        }
        
    }
    cout << fixed << setprecision(5) << ans << endl;
    return 0;
}