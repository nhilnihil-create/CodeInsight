#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    int N,K,ans=0; cin >> N >> K;
    int data[N];
    map<int,int> mp{};
    for(int i=0;i<N;i++) cin >> data[i];
    
    for(int i=0;i<N;i++){
        if(mp[data[i]] == 0) mp[data[i]] = 1;
        else mp[data[i]]++;
    }
    
    vector<int> vec{};
    for(auto itr = mp.begin(); itr != mp.end(); itr++){
        vec.push_back(itr->second);
    }
    sort(vec.begin(),vec.end());
    int size = mp.size();
    int i=0;
    while(1){
        if(size <= K) break;
        ans +=vec[i];
        size--;
        i++;
    }
    cout << ans << endl;
}