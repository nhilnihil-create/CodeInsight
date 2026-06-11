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
    map<int, int> D;
    int M;
    int d, t;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> d;
        if(D.count(d)){
            D[d]++;
        }
        else{
            D[d] = 1;
        }
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> t;
        if(!D.count(t)){
            NO();
            return 0;
        }
        else{
            D[t]--;
            if(D[t] < 0){
                NO();
                return 0;
            }
        }
    }
    YES();

}