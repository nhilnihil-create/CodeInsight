#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll one = 1;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    int N;
    cin >> N;
    vector<int> x(N), y(N), h(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> h[i];
    }
    int ind = 0;
    for (int i = 0; i < N; i++) {
        if(h[i] != 0){
            ind = i;
            break;
        }
    }
    int tmp;
    int check;
    for (int cx = 0; cx < 101; cx++) {
        for (int cy = 0; cy < 101; cy++) {
            tmp = h[ind] + abs(cx - x[ind]) + abs(cy - y[ind]);
            check = true;
            for (int i = 0; i < N; i++) {
                if(i == ind) continue;    
                if(h[i] == 0){
                    if(abs(cx - x[i]) + abs(cy - y[i]) < tmp){
                        check = false;
                    }
                }
                else{
                    if(h[i] + abs(cx - x[i]) + abs(cy - y[i]) != tmp){
                        check = false;
                    }
                }
            }
            if(check){
                printf("%d %d %d\n", cx, cy, tmp);
                return 0;
            }
        }
    }

}