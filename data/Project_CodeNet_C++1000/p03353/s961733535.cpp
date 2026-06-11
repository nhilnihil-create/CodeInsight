#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;

int main(){
    string s;
    cin>>s;
    long N = s.size();
    long K;
    cin>>K;
    vector<string> S;
    map<string,int> mp;
    
    for(long j=1;j<=K;j++){
        for(long i=0;i<=N-j;i++){
            string c = s.substr(i,j);
            if(mp[c]==0){
                S.push_back(c);
                mp[c] = 1;
            }
        }
    }
    
    
    sort(S.begin(),S.end());

    cout<<S[K-1]<<endl;
}
