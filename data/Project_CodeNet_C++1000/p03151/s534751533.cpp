#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define collect(arr, size) rep(i,size) cin >> arr[i];
#define int long long

signed main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    collect(a,n); collect(b,n);
    
    priority_queue<int> excess;
    int lack = 0, changed = 0;
    rep(i,n){
        int c = a[i]-b[i];
        if(c > 0) excess.push(c);
        if(c < 0){
            changed++;
            lack += c;
        }
    }
    
    while(!excess.empty() && lack<0){
        lack += excess.top();
        changed++;
        excess.pop();
    }
    
    if(lack<0){
        changed = -1;
    }
    cout << changed << endl;
}