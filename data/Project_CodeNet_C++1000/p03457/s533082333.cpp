#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N;
    int t[110000],x[110000],y[110000];
    t[0]=0;
    x[0]=0;
    y[0]=0;

    cin >> N;
    
    for (int i=0; i < N; i++){
        cin >> t[i+1] >> x[i+1] >> y[i+1];
    }

    int dt,dist;
    bool can = true;
    for (int i=0; i < N; i++){
        dt = t[i+1] - t[i];
        dist = abs(x[i+1] - x[i]) + abs(y[i+1] - y[i]);

        if(dt < dist){
            can = false;
            break;
        }

        if(!(dt%2 == dist%2)){
            can = false;
            break;
        }


    }

    if(can) cout << "Yes" << endl;
    else cout << "No" << endl;

}