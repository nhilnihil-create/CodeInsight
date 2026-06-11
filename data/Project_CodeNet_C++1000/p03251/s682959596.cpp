#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    int X[n], Y[m];
    for(int i = 0; i < n; i++){
        cin >> X[i];
    }
    for(int i = 0; i < m; i++){
        cin >> Y[i];
    }
    sort(X,X+n);
    sort(Y, Y+m);
    for(int i = x+1; i < y+1; i++){
        if(X[n-1] < i && i <= Y[0]){
            cout << "No War" << endl;
            return 0;
        }
    }
    cout << "War" << endl;
    return 0;
}
