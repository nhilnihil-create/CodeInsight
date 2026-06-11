#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
#define zeros(x) x^(x-1)&x
#define pii pair<ll,ll>
#define cd complex<double>
#define dbg(x) cerr<<x<<endl;
#define Nmax 1000005
#define MOD 1000000007
using namespace std;

ll n,x,y,ans,lst,uz[Nmax],crt;

vector<pii> L,R;

bool comp(pii A, pii B){
    return A.first < B.first;
}

bool comp2(pii A, pii B){
    return A.first > B.first;
}

int main()
{
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> x >> y;
        L.push_back({y,i});
        R.push_back({x,i});
    }
    L.push_back({0,0});
    R.push_back({0,0});
    make_heap(L.begin(),L.end(), comp2);
    make_heap(R.begin(),R.end(), comp);


    for (int i=1;i<=n;i++){
        while(!R.empty() && uz[R[0].second] == 1){
            pop_heap(R.begin(),R.end(),comp);
            R.pop_back();
        }
        if (R.empty()) break;
        crt += R[0].first;
        uz[R[0].second] = 1;

        while(!L.empty() && uz[L[0].second] == 1){
            pop_heap(L.begin(),L.end(),comp2);
            L.pop_back();
        }
        if (L.empty()) break;
        crt -= L[0].first;
        uz[L[0].second] = 1;
        ans = max(ans, crt * 2);
    }

    cout << ans << '\n';

    return 0;
}
