#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;

using namespace std;

int main(){
    int l;  cin >> l;
    string a, b, c;    cin >> a >> b >> c;
    int cnt = 0;
    for(int i=0; i<l; i++){
        if(a[i] == b[i]){
            if(b[i] != c[i])    cnt++;
        }else{
            if(a[i] == c[i])    cnt++;
            else if(b[i] == c[i])    cnt++;
            else    cnt += 2;
        }
    }
    print(cnt);
}