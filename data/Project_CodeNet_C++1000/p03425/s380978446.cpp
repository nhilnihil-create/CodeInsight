#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<char,long long int> mp;
    string s;
    for(int i=0;i<n;i++){
        cin >> s;
        mp[s[0]]++;
    }
    long long int ans=0;
    vector<char> v = {'M','A','R','C','H'};
    for(auto u:v){
        for(auto x:v){
            for(auto y:v){
                if(u!=x && u!=y && x!=y)ans += mp[u]*mp[x]*mp[y];
            }
        }
    }
    ans /= 6;
    cout << ans;
}