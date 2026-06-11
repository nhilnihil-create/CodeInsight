#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    map<int,int> mp;
    for(int i = 0; i < 3; i++){
        int a; cin >> a; mp[a]++;
    }
    for(auto i : mp){
        if(i.second == 1){
            cout << i.first << endl;
            return 0;
        }
    }
}