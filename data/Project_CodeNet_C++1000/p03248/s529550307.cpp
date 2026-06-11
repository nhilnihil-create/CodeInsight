#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    int n = s.size();
    vector<int> arr;
    if(s[n-1]!='0'){
        cout<<-1;
        return 0;
    }
    if (s[0] != '1') {
        cout<<-1;
        return 0;
    }
    for(int i = 0; i < n-1; i++){
        if(s[i]=='1') arr.push_back(i+1);
        if(s[i] == '1' && s[i]!=s[n-i-2]){
            cout<<-1;
            return 0;
        }
    }

    int cur = 1;
    int prv = 0;
    int pnod = 0;
    vector<pair<int,int>> e;
    for(int i = 0; i < (int)arr.size(); i++){
        if(i!=0) e.push_back({pnod,cur});
        int sz = arr[i] - prv;
        pnod = cur;
        if(i != (int)arr.size()-1){
            sz--;
        }
        for(int j = 0; j < sz; j++){
            e.push_back({cur,cur+j+1});
        }
        cur+=sz+1;
        prv=cur-1;
    }
    if(prv<n){
        e.push_back({pnod,cur});
        for(int i = 0; i < n - prv; i++) e.push_back({cur,cur+i+1});
    }

    for(auto i : e) cout<<i.first<<" "<<i.second<<endl;
}
