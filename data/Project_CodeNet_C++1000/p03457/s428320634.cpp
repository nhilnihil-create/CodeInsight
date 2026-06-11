#include <bits/stdc++.h>
using namespace std;

long long n,m,c,x,y,a,b,t,dt, hasil=0, tag, dist;
int arr[200001];
bool mulai[200001];
bool sel[200001];
bool valid = true;

int main() {
    cin >> m;
    a = 0;
    b = 0;
    for (int i = 1; i <= m; i++){
        cin >> t >> x >> y;
        dt = t-hasil;
        dist = (abs(x-a) + abs(y-b));
        if ( (dt-dist)% 2 == 0 && dt >= dist){
            a = x;
            b = y;
            hasil = t;
        }
        else {
            valid = false;
            break;
        }
        
    }
    if(valid == true){
        cout << "Yes" << endl;
    }
    else cout << "No" <<  endl;
   
}
    