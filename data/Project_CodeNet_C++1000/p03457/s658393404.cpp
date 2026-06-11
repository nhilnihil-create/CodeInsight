#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int t[n+1],x[n+1],y[n+1];
    t[0]=0; x[0]=0; y[0]=0;
    for(int i=1;i<n+1;i++){
        cin >> t[i] >> x[i] >> y[i];
        if(t[i]-t[i-1] < abs(x[i]-x[i-1])+abs(y[i]-y[i-1])
          || ( (t[i]-t[i-1] > abs(x[i]-x[i-1])+abs(y[i]-y[i-1])) 
          && ( ( (t[i]-t[i-1])%2 != abs(x[i]-x[i-1])%2 + abs(y[i]-y[i-1])%2 ) )) ){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes" << endl;
}