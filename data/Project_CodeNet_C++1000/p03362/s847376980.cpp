#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//エラトステネスの篩
vector<bool> IsPrime;
void e_sieve(int size){
    size=max(2,size);
    IsPrime.assign(size,true);
    IsPrime[0]=false;
    IsPrime[1]=false;
    int chk=2;
    while(chk*chk<=size) {
        if(IsPrime[chk]){
            int tchk=chk*2;
            while(tchk<=size){
                IsPrime[tchk]=false;
                tchk+=chk;
            }
        }
        chk++;
    }
}

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    e_sieve(55555);
    vector<int> cnt;
    for(int i = 0; i < 55555; i++) {
        if(IsPrime[i] && i%5==1) cnt.emplace_back(i);
    }

    for(int i = 0; i < n; i++) {
        cout << cnt[i] << " ";
    }
    cout << "\n";

    return 0;
}