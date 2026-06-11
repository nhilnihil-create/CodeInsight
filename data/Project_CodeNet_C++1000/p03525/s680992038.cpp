#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ll n;cin >> n;
    vector<int> v;
    map<int, int> mp;
    for(int i = 0;i < n;i++){
        int d;cin >> d;
        v.push_back(d);
        mp[d]++;
    }
    mp[0]++;
    vector<int> fff(12);
    int ans = 0;
    auto check = [&](){
        vector<int> vf(24);
        for(auto a : mp){
            if(a.first == 0 || a.first == 12){
                if(a.second >= 2){
                    return;
                }else{
                    vf[a.first] = 1;
                }
            }else{
                if(a.second >= 3){
                    return;
                }else if(a.second == 2){
                    vf[a.first] = 1;
                    vf[24 - a.first] = 1;
                }else{
                    if(fff[a.first] == 0){
                        vf[24 - a.first] = 1;
                    }else{
                        vf[a.first] = 1;
                    }
                }
            }
        }
        int ss = 1e9;
        for(int i = 0;i < vf.size()-1;i++){
            for(int j = i + 1;j < vf.size();j++){
                if(vf[i] == 1 && vf[j] == 1)ss = min(min(24 - (j - i), j - i), ss);
            }
        }
        ans = max(ans, ss);
    };

    function<void(int)> f = [&](int i){
        if(i == fff.size()){
            check();
            return;
        }
        fff[i] = 0;f(i + 1);
        fff[i] = 1;f(i + 1);
    };
    f(0);
    check();
    cout<<ans<<endl;
}
