#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
typedef long long ll;

int N;
ll rui[200010];
ll sum(int l, int r){
    return rui[r] - rui[l-1];
}

ll L_sm[200010], L_bg[200010];
ll R_sm[200010], R_bg[200010];

void L_init(){
    for(int i=2, j=1;i<=N;i++){
        for(;j+2<=i;j++){
            if(abs(sum(1,j)-sum(j+1,i)) < abs(sum(1,j+1)-sum(j+2, i))){
                break;
            }
        }
        L_sm[i] = min(sum(1, j), sum(j+1, i));
        L_bg[i] = max(sum(1, j), sum(j+1, i));
    }
}

void R_init(){
    for(int i=N-1, j=N;i>=0;i--){
        for(;j-2>=i;j--){
            if(abs(sum(i, j-2)-sum(j-1, N)) > abs(sum(i, j-1)-sum(j, N))){
                break;
            }
        }
        R_sm[i] = min(sum(i, j-1), sum(j, N));
        R_bg[i] = max(sum(i, j-1), sum(j, N));
    }
}

int main(){

    cin >> N;
    rep(i, N){
        cin >> rui[i+1];
        rui[i+1] += rui[i];
    }
    L_init();
    R_init();
    
    //for(int i=1;i<=N;i++)cout << L_bg[i] << (i==N ? "\n" : " ");
    //for(int i=1;i<=N;i++)cout << L_sm[i] << (i==N ? "\n" : " ");
    //for(int i=1;i<=N;i++)cout << R_bg[i] << (i==N ? "\n" : " ");
    //for(int i=1;i<=N;i++)cout << R_sm[i] << (i==N ? "\n" : " ");
    
    ll ans = 1e17;
    for(int i=2;i+2<=N;i++){
        ll bg = max(L_bg[i], R_bg[i+1]);
        ll sm = min(L_sm[i], R_sm[i+1]);
        ans = min(ans, bg-sm);
    }
    cout << ans << endl;

    return 0;
}