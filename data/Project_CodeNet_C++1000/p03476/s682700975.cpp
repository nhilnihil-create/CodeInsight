#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

bool check(int n){
    for (int i=2; i*i<=n; i++){
        if (n % i == 0) return false;
    }
    return true;
}

vi vec(100010);
void primes(void){
    REP(i,3,100001){
        if (check(i) && check((i+1)/2)) vec[i+1] = vec[i] + 1;
        else vec[i+1] = vec[i];
        //printf("%d ", vec[i]);
    }
    //printf("\n");
}


int main(){
    int q;
    cin >> q;

    primes();
    rep(i,60){
        //printf("i:%d vec[i]:%d\n", i, vec[i]);
    }
    rep(i,q){
        int l, r;
        cin >> l >> r;
        int ans = vec[r+1] - vec[l];
        cout << ans << endl;
    }
    return 0;
}
