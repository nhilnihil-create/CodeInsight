#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ans;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        if(a[i] > i + 1){
            cout << -1 << endl;
            return 0;
        }
    }
    while(!a.empty()){
        vector<int> b;
        for(int i = 0; i < a.size(); i++){
            if(a[i] == i + 1){
                b.emplace_back(i);
            }
        }
        ans.emplace_back(a[b.back()]);
        a.erase(a.begin() + b.back());
    }
    reverse(ans.rbegin(),ans.rend());
    for(auto v:ans)cout << v << endl;
}