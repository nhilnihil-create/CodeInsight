#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <queue>
#include <math.h>
#include <bitset>
#define INF 100000000000
#define N 100001
#define ll long long
using namespace std;

int main(){
    string s;
    int k;
    cin>>s>>k;
    
    vector<string> data;
    for (int i=1; i<=k; i++){
        for (int j=0; j<s.size()-i+1; j++){
            string l;
            l=s[j];
            for (int p=1; p<i; p++){
                l+=s[j+p];
            }
            data.push_back(l);
        }
    }
    
    set<string> st;
    
    for (int i=0; i<data.size(); i++){
        st.insert(data[i]);
    }
    
    vector<string> ans;
    for (auto x:st){
        string p=x;
        ans.push_back(p);
    }
    
    cout<<ans[k-1]<<endl;
}