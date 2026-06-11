#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int n, y;
    cin >> n >> y;
    int r10000 = -1, r5000 = -1, r1000 = -1;
    for(int a = 0; a <= n; a++){
        for(int b = 0; a + b <= n; b++){
            int c = n - a - b;
            int sum = 10000*a + 5000*b + 1000*c;
            if(sum == y){
                r10000 = a;
                r5000 = b;
                r1000 = c;
            }
        }
    }

    cout << r10000 << " " << r5000 << " " << r1000 << endl;
    return 0;
}