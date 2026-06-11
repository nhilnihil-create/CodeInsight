#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    double t,a;
    cin >> n >> t >> a;
    vector<double> h(n);

    for(int i=0; i<n; i++){
        cin >> h.at(i);
        h.at(i)*=0.006;
    }

    int ans;
    double x,y=1000;
    for(int i=0; i<n; i++){
        x=abs(a-(t-h.at(i)));
        if(y>x){
            ans=i+1;
            y=x;
        }
    }
    cout << ans << endl;
}