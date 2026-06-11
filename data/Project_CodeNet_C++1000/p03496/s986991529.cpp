#include <bits/stdc++.h>

using namespace std;
using LL = long long;
const LL LINF = 1e18;
const LL MOD = 1e9+7;


int main(){
    int N;cin >> N;
    vector<int> vec;
    vector<pair<int,int>> ans;
    for(int a = 0;a < N;a++){
        int b;cin >> b;
        vec.push_back(b);
    }
    if(abs(*max_element(vec.begin(),vec.end())) > abs(*min_element(vec.begin(),vec.end()))){
        for(int a = 0;a < N;a++){
            ans.push_back({max_element(vec.begin(),vec.end())-vec.begin(), a});
        }
        for(int a = 0;a < N-1;a++){
            ans.push_back({a,a+1});
        }
    }else{
        for(int a = 0;a < N;a++){
            ans.push_back({min_element(vec.begin(),vec.end())-vec.begin(), a});
        }
        for(int a = N-1;a >= 1;a--){
            ans.push_back({a,a-1});
        }
    }
    cout<<ans.size()<<endl;
    for(int a = 0;a < ans.size();a++){
        cout<<ans.at(a).first+1<<" "<<ans.at(a).second+1<<endl;
    }
}
