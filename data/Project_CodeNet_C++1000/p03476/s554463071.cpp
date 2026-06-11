#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<bool> IsPrime;
void e_sieve(int size){
    size=max(2,size);
    IsPrime.assign(size,true);
    IsPrime[0]=false;
    IsPrime[1]=false;
    int chk=2;
    while(chk*chk<=size) {
        int tchk=chk*2;
        while(tchk<=size){
            IsPrime[tchk]=false;
            tchk+=chk;
        }
        chk++;
    }
}

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    vector<int> l(q);
    vector<int> r(q);
    int rx=0;
    for(int i = 0; i < q; i++) {
        cin >> l[i] >> r[i];
        rx=max(r[i],rx);
    }
    rx++;
    e_sieve(rx);
    vector<int> cnt(rx);

    int add=0;
    for(int i = 0; i < rx; i++) {
        if(IsPrime[i]==true && IsPrime[(i+1)/2]==true) add++;
        cnt[i]=add;
//        cout << cnt[i] << " ";
    }
    for(int i = 0; i < q; i++) {
        int tans=cnt[r[i]]-cnt[l[i]-1];
        cout << tans << "\n";
//        cout << cnt[r[i]+1] << " " << cnt[l[i]] << "\n";
    }
    return 0;
}