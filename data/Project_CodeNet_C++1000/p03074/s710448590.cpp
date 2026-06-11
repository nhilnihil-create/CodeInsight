#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<int,int>> vp;
    int idx=0;
    while(idx < n){
        int cnt = 0;
        char c = s.at(idx);
        while(idx < n && s.at(idx) == c){
            cnt++;
            idx++;
        }
        vp.push_back({c-'0',cnt});
    }
    // for(auto p:vp){
    //     cout << p.first << " " << p.second << endl;
    // }
    vector<int> v(vp.size()+10);
    int ofs = (vp.at(0).first+1) % 2; // "1" start
    rep(i,vp.size()){
        v.at(i+ofs) = vp.at(i).second;
    }

    int ln = k*2+1;
    int res = 0;
    int tot = 0;
    for(int i=0;i<min(ln,(int)v.size());i++){
        tot += v.at(i);
    }
    res = tot;
    for(int i=2;i+ln-1<v.size()-1;i+=2){
        tot -= v.at(i-1)+v.at(i-2);
        tot += v.at(i+ln-1)+v.at(i+ln-2);
        res = max(res,tot);
    }
    // rep(i,v.size()){
    //     cout << v.at(i) << " ";
    // }
    // cout << endl;
    cout << res << endl;
    return 0;
}