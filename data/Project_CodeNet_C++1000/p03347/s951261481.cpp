#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    bool flag = true;
    int temp = 0;
    ll res=0;
    for(int i=a.size()-1;i>=0;--i){
        if(a[i]>=temp){
            if(i-a[i]>=0){
                //cout << "i:a[i]" << i << ":" << a[i] << endl;
                res+=a[i];
            }
            else{
                flag = false;
                break;
            }
        }
        else if(a[i]+1==temp){
             temp = a[i];
            continue;
        }
        else{
            flag = false;
            break;
        }
        temp = a[i];
    }
    if(flag) cout << res << endl;
    else cout << -1 << endl;
}