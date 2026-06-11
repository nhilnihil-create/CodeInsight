#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;cin>>n;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++) {
        int x;cin>>x;
        mp[x]++;
    }
    int res=0;
    for(auto i:mp) {
        if(i.first <= i.second)
            res += i.second-i.first;
        else
            res += i.second;
    }
    cout<<res<<endl;
}