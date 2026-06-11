#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
int main(){
    int n;cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int mx=0;
    int num=-1;
    bool allP=true;
    bool allM=true;
    for(int i=0;i<n;i++){
        if(a[i]<0) allP=false;
        else if(a[i]>0) allM=false;
        if(abs(a[i])>abs(mx)){
            mx=a[i];
            num=i+1;
        }
    }
    //cout << mx << " " << endl;
    vector<P> ans;
    if(mx==0){
        cout << 0 << endl;
        return 0;
    }
    if(allP){
        for(int i=1;i<n;i++) ans.push_back({i,i+1});
        cout << n-1 << endl;
        for(int i=0;i<(int)ans.size();i++) cout << ans[i].first << " " << ans[i].second << endl;
    }
    else if(allM){
        for(int i=n;i>=2;i--) ans.push_back({i,i-1});
        cout << n-1 << endl;
        for(int i=0;i<(int)ans.size();i++) cout << ans[i].first << " " << ans[i].second << endl;
    }
    else{
        int cnt=0;
        if(mx<0){
            for(int i=0;i<n;i++){
                if(a[i]>0){
                    ans.push_back({num,i+1});
                    cnt++;
                }
            }
            for(int i=n;i>=2;i--) ans.push_back({i,i-1});
            cnt+=n-1;
            cout << cnt << endl;
            for(int i=0;i<(int)ans.size();i++) cout << ans[i].first << " " << ans[i].second << endl;
        }
        else{
            //cout << "kitayo" << endl;
            for(int i=0;i<n;i++){
                if(a[i]<0){
                    ans.push_back({num,i+1});
                    cnt++;
                }
            }
            //cout << cnt << endl;
            for(int i=1;i<n;i++) ans.push_back({i,i+1});
            cnt+=n-1;
            cout << cnt << endl;
            for(int i=0;i<(int)ans.size();i++) cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
    return 0;
}