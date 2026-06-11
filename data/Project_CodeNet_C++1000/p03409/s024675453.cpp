#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int,int>> r(n);
    for(int i = 0; i < n; i++) {
        cin >> r[i].second >> r[i].first;
        r[i].first*=-1;
    }
    vector<pair<int,int>> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i].first >> b[i].second;
    }
    sort(r.begin(),r.end());
    sort(b.begin(),b.end());
    for(int i = 0; i < n; i++) {
        r[i].first*=-1;
    }


    vector<bool> a(n,false);
    int cnt=0;
    for(int i = 0; i < n; i++) {
        int idx=0;
        int bx=b[i].first;
        int by=b[i].second;
        while(idx<n) {
            int ry=r[idx].first;
            int rx=r[idx].second;
            if(rx<bx && ry<by && a[idx]==false){
                a[idx]=true;
                cnt++;
                break;
            }
            idx++;
        }
    }
    cout << cnt << "\n";
    return 0;
}