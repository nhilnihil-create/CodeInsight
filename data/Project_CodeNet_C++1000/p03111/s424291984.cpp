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
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<int> L(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }

    vector<int> check(N);
    int tmp;
    int a, b, c;
    int ans = inINF;
    int tans;

    for (int i = 0; i < 1<<(2*N); i++) {
        tmp = i;
        a = 0; b = 0; c = 0;
        tans = 0;
        for (int j = 0; j < N; j++) {
            if(tmp % 4 == 0){
                a += L[j];
                tans += 10;
            }
            else if(tmp % 4 == 1){
                tans += 10;
                b += L[j];
            }
            else if(tmp % 4 == 2){
                tans += 10;
                c += L[j];
            }
            tmp = tmp / 4;
        }
        if(a == 0 || b == 0 || c == 0){
            continue;
        }

        if(a < b){
            tmp = a;
            a = b;
            b = tmp;
        }
        if(b < c){
            tmp = b;
            b = c;
            c = tmp;
        }
        if(a < b){
            tmp = a;
            a = b;
            b = tmp;
        }

        tans += abs(A-a) + abs(B-b) + abs(C-c);
        tans -= 30;
        ans = min(ans, tans);

    }

    printf("%d\n", ans);
}   