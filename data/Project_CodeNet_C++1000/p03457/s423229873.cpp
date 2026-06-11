#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'

int main(){
    int n;
    cin >> n;
    int t, x, y;
    int pt=0, px=0, py=0;
    for(int i=0; i<n; ++i){
        cin >> t >> x >> y;
        t -= pt;
        x = abs(x-px);
        y = abs(y-py);

        if(x+y <= t){
            if(t-(x+y)&1){
                cout << "No";
                return 0;
            }
        }
        else{
            cout << "No";
            return 0;
        }
        pt = t;
        px = x;
        py=y;
    }
    cout << "Yes";
}
