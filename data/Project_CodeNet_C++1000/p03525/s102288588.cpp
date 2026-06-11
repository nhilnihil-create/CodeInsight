#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> cnt(13);
    for(int i = 0; i < n; i++){
        int d;
        cin >> d;
        cnt[d]++;
    }
    vector<int> aa;
    aa.push_back(0);
    if(cnt[0] || cnt[12] >= 2){
        cout << 0 << endl;
        return 0;
    }
    if(cnt[12] == 1)
        aa.push_back(12);
    bool flip = true;
    for(int i = 1; i < 12; i++){
        switch(cnt[i]){
            case 0:
                break;
            case 1:
                if(flip) aa.push_back(i);
                else aa.push_back(24-i);
                flip = !flip;
                break;
            case 2:
                aa.push_back(i);
                aa.push_back(24-i);
                break;
            default:
                cout << 0 << endl;
                return 0;
        }
    }
    int mn = 24;
    aa.push_back(24);
    sort(aa.begin(), aa.end());
    for(int i = 0; i+1 < aa.size(); i++){
        if(mn > aa[i+1]-aa[i]) mn = aa[i+1]-aa[i];
    }
    cout << mn << endl;
    return 0;
}