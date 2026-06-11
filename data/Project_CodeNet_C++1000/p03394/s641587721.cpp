#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    int N;
    cin >> N;
    if(N == 3){
        printf("2 5 63\n");
        return 0;
    }
    else if(N <= 32){
        printf("2 3 4 9 ");
        for (int i = 4; i < N; i++) {
            printf("%d ", 6 * (i-3));
        }
        printf("\n");
        return 0;
    }
    else{
        for (int i = 0; i < ((N-1)/8)+1; i++) {
            printf("%d %d %d %d %d %d ", 12*i+2, 12*i+3, 12*i+4, 12*i+8, 12*i+9, 12*i+10);
        }
        for (int i = 0; i < 2*(((N-1)/8)+1) - (7 - (N-1)%8); i++) {
            printf("%d ", 6*(i+1));
        }
        printf("\n");
    }

}   