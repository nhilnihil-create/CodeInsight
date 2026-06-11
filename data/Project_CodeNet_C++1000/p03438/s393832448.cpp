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
    vector<ll> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> b[i];
    }   
    ll ca = 0; ll cb = 0;
    ll ma = 0;
    for (int i = 0; i < N; i++) {
        ma += b[i]; ma -= a[i];
    }
    for (int i = 0; i < N; i++) {
        if(a[i] > b[i]){
            cb += a[i] - b[i];
        }
        else if(a[i] < b[i]){
            if((b[i] - a[i]) % 2 == 0){
                ca += (b[i] - a[i]) / 2;
            }
            else{
                ca += (b[i] + 1- a[i]) / 2;
                cb += 1;
            }
        }
    }
    if(ca <= ma && cb <= ma){
        Yes();
    }
    else{
        No();
    }

}