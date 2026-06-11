#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
typedef vector<int> vec;
typedef vector<int64> vec64;
#define db(x) cout << "> " << #x << ": " << x << "\n";
#define ss cout << " ";
#define ct(x) cout << x;
#define nn cout << "\n";
#define cts(x) cout << x << " ";
#define ctn(x) cout << x << "\n";
#define qr queries();
void solve();
void YN(bool b){if (b){ctn("YES");}else{ctn ("NO");}};
void yn(bool b){if (b){ctn("Yes");}else{ctn ("No");}};
void queries(){int n;cin >> n;while (n--)solve();}
// // // // // // // // // // // // // // // // // // // // // // 
/*                  TEMPLATE - VANILLA                         */
// // // // // // // // // // // // // // // // // // // // // //
int64 q, n;

void solve(){

    return;
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    cin >> s;
    bool a = 0, b = 0;
    int n1 = 0, n2 = 0;
    for (int i = 0; i < 2; i++){
        n1 = n1 * 10 + (int) s[i] - 48;
    }
    for (int i = 2; i < 4; i++){
        n2 = n2 * 10 + (int) s[i] - 48;
    }
    if (n1 <= 12 && n1 != 0){
        a = 1;
    }
    if (n2 <= 12 && n2 != 0){
        b = 1;
    }
    // cts(n1); ctn(n2);
    // cts(a); ctn(b);
    if (a && b){
        ctn("AMBIGUOUS");
    }
    else if (a){
        ctn("MMYY");
    }
    else if (b){
        ctn("YYMM");
    }
    else{
        ctn("NA");
    }
    return 0;
}
