#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,t;
    cin >> n >> t;

    int cmin=1e9;
    for(int i=0;i<n;i++){
        int cost,time;
        cin >> cost >> time;
        if(time<=t){
            if(cmin>=cost){
                cmin=cost;
            }
        }
    }
    if(cmin==1e9) cout << "TLE" << endl;
    else cout << cmin << endl;
}