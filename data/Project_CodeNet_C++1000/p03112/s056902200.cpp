#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lp pair<long, long>

const ll inf = (ll)1 << 40;
ll A, B, Q;
ll bu1[100010], bu2[100010];
ll res1[100010], res2[100010];
int binary_search(int lb, int ub, ll x, ll* bu){
    if(ub - lb == 1) return ub;
    
    int mid = (ub + lb) / 2;
    
    if(bu[mid] < x) lb = mid;
    else ub = mid;

    return binary_search(lb, ub, x, bu);
}

ll solve(ll x){
    int ub1 = binary_search(0, A, x, bu1);
    int ub2 = binary_search(0, B, x, bu2);
    ll dist1 = min(abs(bu1[ub1] - x) + res1[ub1], abs(bu1[ub1 - 1] - x) + res1[ub1 - 1]);
    ll dist2 = min(abs(bu2[ub2] - x) + res2[ub2], abs(bu2[ub2 - 1] - x) + res2[ub2 - 1]);
    return min(dist1, dist2);
}

void culc(ll* dat1, ll* dat2, ll* res, int s1, int s2){
    for(int i = 1; i <= s1; i++){
        int ub = binary_search(0, s2, dat1[i], dat2);
        res[i] = min(abs(dat1[i] - dat2[ub]), abs(dat1[i] - dat2[ub - 1]));
    }
}

int main(){
    cin >> A >> B >> Q;
    
    bu1[0] = bu1[A + 1] = inf; 
    bu2[0] = bu2[B + 1] = inf;
    res1[0] = res1[A + 1] = inf;  
    res2[0] = res2[B + 1] = inf;  
    
    for(int i = 1; i <= A; i++){
        cin >> bu1[i];
    }
    for(int i = 1; i <= B; i++){
        cin >> bu2[i];
    }

    culc(bu1, bu2, res1, A, B);
    culc(bu2, bu1, res2, B, A);

    for(int i = 0; i < Q; i++){
        ll x;
        cin >> x;
        cout << solve(x) << endl;
    }
    return 0;
}