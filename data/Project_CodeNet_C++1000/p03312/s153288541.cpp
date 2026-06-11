#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////

ll N,A[202020];
ll As[202020];
ll i, j, k,ans;

bool bs(ll aa){
    ll i;
    fornum(i,2,N-1){
        ll cd = i;
        ll bc = upper_bound(As, As + i, As[i] / 2) - As;
        if(abs(As[i]-As[bc-1]*2)<abs(As[i]-As[bc]*2)){
            bc--;
        }

        ll de = upper_bound(As, As + N, (As[N] - As[i]) / 2 + As[i]) - As;
        if(abs(As[N]-As[de-1]*2+As[i])<abs(As[N]-As[de]*2+As[i])){
            de--;
        }
        ll mx = max(max(As[bc], As[cd] - As[bc]), max(As[de] - As[cd], As[N] - As[de]));
        ll mn = min(min(As[bc], As[cd] - As[bc]), min(As[de] - As[cd], As[N] - As[de]));

        //printf("%lld:%llda%lldb%lldc%lld\n", aa, bc, cd, de, abs(mx - mn));
        if(abs(mx-mn)<=aa){
            return true;
        }
    }
    return false;
}

int main(){
    scanf("%lld", &N);
    fornum(i,0,N){
        scanf("%lld", &A[i]);
        As[i + 1] = As[i] + A[i];
    }
    sort(A, A + N);
    ll b = A[N / 2];
    fornum(i,0,N){
        ans += abs(A[i] - b);
    }

    ll l = 0, r = 1e18;
    while(l<r){
        ll c = (l + r) / 2;
        if(bs(c)){
            r = c;
        }else{
            l = c + 1;
        }
    }

    printf("%lld\n", r);
    return 0;
}