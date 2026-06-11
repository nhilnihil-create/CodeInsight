#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;
//stoi(s) : string→int stoll(s) :string→longlong  int→string to_string(i)
const double PI = acos(-1.0);
//小数点の表し方 cout << fixed << setprecision(5);

int yoriooki(ll a,vector<ll> vec){ //aより大きい数の要素数
    ll len = vec.size();
    auto iter_upper = upper_bound(vec.begin(), vec.end(), a);
    ll idx_upper = distance(vec.begin(), iter_upper);
    return len - idx_upper;
}

int yoritisai(ll a,vector<ll> vec){ //aより小さい要素数
    ll len = vec.size();
    auto iter_lower = lower_bound(vec.begin(), vec.end(), a);
    ll idx_lower = distance(vec.begin(), iter_lower); 
    return idx_lower;
}

int main(){
    int n;
    cin >> n;
    vector<ll> a(n),b(n),c(n);map<ll,int> ma,mb,mc; 
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    for(int i=0;i<n;i++){
        cin >> c[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll now_b = b[i];
        ll now_a = 0;
        ll now_c = 0;
        auto itrA = lower_bound(a.begin(),a.end(),now_b);
        ll idxA = itrA - a.begin();
        auto itrB = upper_bound(c.begin(),c.end(),now_b);
        ll idxB = itrB - c.begin();
        idxB = n - idxB;

        ans += idxA * idxB;


    }
    cout << ans << endl;

}

