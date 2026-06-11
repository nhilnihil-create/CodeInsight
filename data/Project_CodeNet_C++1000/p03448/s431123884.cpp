#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<29;
using namespace std;
using ll = long long;
ll l , a[500001];
int main(){
    int a , b , c , n , s = 0;
    cin >> a >> b >> c >> n;
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            for(int k = 0; k <= c; k++){
                if(i * 500 + j * 100 + k * 50 == n){
                    s++;
                }
            }
        }
    }
    cout << s << endl;
}
