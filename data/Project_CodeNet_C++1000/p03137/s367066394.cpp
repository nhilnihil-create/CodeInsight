#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int>x(m);
    for(int i=0;i<m;i++)cin >> x[i];
    if(n>m){
        cout << 0;
        return 0;
    }
    sort(x.begin(),x.end());
    vector<int>lon_g(m);
    for(int i=0;i<m-1;i++){
        lon_g[i]=abs(x[i]-x[i+1]);
    }
    sort(lon_g.begin(),lon_g.end());
    reverse(lon_g.begin(),lon_g.end());
    int kyori=0;
    for(int i=0;i<n-1;i++)kyori+=lon_g[i];
    cout << x[m-1]-x[0]-kyori << endl;
}
