#include <bits/stdc++.h>
using namespace std;

const int N = 1050, PW = 31;

int n;
int pw2[PW];
char ans[PW];
int x[N], y[N];
int dx[4] = {0,0,-1,1}, dy[4] = {1,-1,0,0};
char drc[4] = {'D','U','R','L'};


bool in_bound(int x, int y, int pi){
    return x + y <= (pw2[pi]-1) && x + y >= -(pw2[pi]-1) && y - x <= (pw2[pi]-1) && y - x >= -(pw2[pi]-1);
}

int main(){
    pw2[0] = 1;
    for(int i = 1; i < PW; i++) pw2[i] = pw2[i-1] * 2;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for(int i = 0; i < n; i++){
        if(((x[i] + y[i]) % 2 + 2) % 2 != ((x[0] + y[0]) % 2 + 2) % 2) return !printf("-1");
    }

    bool even = ((x[0] + y[0]) % 2 + 2) % 2 == 0;
    if(even){for(int i = 0; i < n; i++) x[i]--;}

    cout << (even ? PW+1 : PW) << endl;
    for(int i = 0; i < PW; i++) cout << pw2[i] << " ";
    if(even) cout << 1;
    cout << endl;
    for(int i = 0; i < n; i++){
        for(int pi = PW-1; pi >= 0; pi--){
            for(int d = 0; d < 4; d++){
                if(in_bound(x[i] + dx[d] * pw2[pi], y[i] + dy[d] * pw2[pi], pi)){
                    ans[pi] = drc[d];
                    x[i] += dx[d] * pw2[pi];
                    y[i] += dy[d] * pw2[pi];
                    break;
                }
            }
        }
        for(int j = 0; j < PW; j++) cout << ans[j];
        if(even) cout << 'R';
        cout << endl;
    }

}