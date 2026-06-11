#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;


int main(){
    int N;
    cin >> N;
    vector<int> jewelry_value;
    vector<int> jewelry_cost;
    
    rep(i,N){
        int x;
        cin >> x;
        jewelry_value.push_back(x);
    }
    
    rep(i,N){
        int x;
        cin >> x;
        jewelry_cost.push_back(x);
    }
    
    
    int ans=0;
    rep(i,N){
        int V,C;
        V=jewelry_value[i];
        C=jewelry_cost[i];
        
        if(V-C > 0){
            ans += V-C;
        }
    }
    cout << ans << endl;
}
