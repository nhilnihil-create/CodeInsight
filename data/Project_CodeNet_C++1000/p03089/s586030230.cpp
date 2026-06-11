#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ans;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        bool end = true;
        for(int j = a.size()-1; j >= 0; j--){
            if(a[j] == j+1){
                ans.push_back(a[j]);
                if(a.size() != 1) a.erase(a.begin()+j);
                //for(auto p:a) cout << p;
                //cout << endl;
                end = false;
                break;
            }
        }
        if(end) {
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto p:ans){
        cout << p << endl;
    }
    return 0;
}