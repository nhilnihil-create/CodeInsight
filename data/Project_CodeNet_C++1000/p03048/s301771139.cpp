#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    int cnt=0;
    for(int R=0; R<=n; R++){
        for(int G=0; G<=n; G++){
            int B = (n-(r*R + G*g))/b;
            if(R*r + G*g + B*b == n && B >=0 ) cnt++;
        }
    }
    cout << cnt <<endl;
}