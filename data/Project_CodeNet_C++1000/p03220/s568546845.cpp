#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t,a;
    cin >> n >> t >> a;
    double h;
    int ans=0;
    double tmp=1e9+1.0;
    for(int i=0;i<n;i++){
        cin >> h;
        if(abs((double)1.0*tmp-1.0*a)>abs(1.0*a-1.0*t+h*0.006)){
            ans=i+1;
            tmp=1.0*t-h*0.006;
        }
    }
    cout << ans << endl;
}