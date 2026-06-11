#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()
template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin>> a[i];
    }
    int ans=0;
    int active=0;
    for(int i=0; i<n; ++i){
        if(active >= a[i]){
            active = a[i];
        }
        else{
            ans+=a[i]-active;
            active = a[i];
        }
    }
    cout << ans;
}