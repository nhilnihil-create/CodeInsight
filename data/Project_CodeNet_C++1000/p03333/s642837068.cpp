#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> pii;
typedef long long ll;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

int N;
int L[100010];
int R[100010];

int main(){

    cin >> N;
    for(int i = 0; i < N; i++) cin >> L[i] >> R[i];
    sort(L, L + N, greater<int>());
    sort(R, R + N);
    ll c = 0;
    ll ans = -1;
    for(int i = 0; i < N; i++){
        c += L[i];
        ans = max(ans, c);
        c -= R[i];
        ans = max(ans, c);
    }
    c = 0;
    for(int i = 0; i < N; i++){
        c -= R[i];
        ans = max(ans, c);
        c += L[i];
        ans = max(ans, c);
    }
    
    cout << ans * 2 << endl;
    

    return 0;
}
