#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    bool possible=true;
    vector<int> t(n+1,0);
    vector<int> x(n+1,0);
    vector<int> y(n+1,0);
    for(int i=0; i<n; i++){
        cin >> t.at(i+1) >> x.at(i+1) >> y.at(i+1);
    }
    for(int i=0; i<n; i++){
        int dt,dx,dy;
        dt=t.at(i+1)-t.at(i);
        dx=abs(x.at(i+1)-x.at(i));
        dy=abs(y.at(i+1)-y.at(i));
        if(dt < dx+dy) possible=false;
        if((dt-dx-dy)%2 == 1) possible=false; 
    }
    if(possible) cout << "Yes" << endl;
    else cout << "No" << endl;
}