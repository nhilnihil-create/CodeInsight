#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef  long long ll;
#define MAX 100000

int main(void){
    int N;
    int x[MAX+5],y[MAX+5],t[MAX+5];
    bool flag = true;
    
    cin >> N;

    x[0] = y[0] = t[0] = 0;

    rep(i, N)
        cin >> t[i+1] >> x[i+1] >> y[i+1];

    rep(i,N){
        int dist = abs(x[i+1]-x[i])+ abs(y[i+1]-y[i]);
        int dt = t[i+1] -t[i];

        if (dist > dt || dist % 2 != dt % 2)
            flag = false;
    }
    
    if(flag)
        cout << "Yes" << endl;

    else
        cout << "No" << endl;
    
    return 0;
}