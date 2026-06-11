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
    int n;
    int k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++){
        if (i == k - 1){
            if (s[i] == 'A'){
                s[i] = 'a';
            }
            if (s[i] == 'B'){
                s[i] = 'b';
            }
            if (s[i] == 'C'){
                s[i] = 'c';
            }
        }
    }
    ctn(s);
    return 0;
}
