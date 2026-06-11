#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    int n,m,X,Y;
    cin >> n >> m >> X >> Y;
    vector<int> x(n), y(m);
    for(int i=0;i<n;i++){
        cin >> x[i];
    } 
    for(int i=0;i<m;i++){
        cin >> y[i];
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int z1 = max(X,x[n-1]);
    int z2 = min(Y,y[0]);
    if(z1<z2){
        cout << "No War"<< endl;
    }else{
        cout << "War" << endl;
    }
}