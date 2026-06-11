#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int>X(n+1);
    vector<int>Y(m+1);

    for(int i=0; i<n; i++){
        cin >> X[i];
    }
    X[n]=x;

    for(int i=0; i<m; i++){
        cin >> Y[i];
    }
    Y[m]=y;

    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());

    if(abs(X[n]-Y[0])<1){
        cout << "War" << endl;
        return 0;
    }

    if(X[n]>Y[0]){
        cout << "War" << endl;
        return 0;
    }

    cout << "No War" << endl;

    return 0;
}