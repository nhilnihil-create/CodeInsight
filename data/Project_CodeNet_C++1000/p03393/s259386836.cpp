#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    string s;
    cin>>s;
    int n=s.length();
    if(n<=25){
        set<char>se;
        rep(i,n){
            se.insert(s[i]);
        }
        for(int i='a'; i<='z'; ++i){
            if(se.find(i)==se.end()){
                s+=i;
                break;
            }
        }
        cout<<s<<endl;
    }
    else{
        if(s=="zyxwvutsrqponmlkjihgfedcba"){
            cout<<-1<<endl;
        }
        else{
            vector<char>x;
            int max1=0;
            while(!s.empty()){
                char c=s.back();
                x.push_back(c);
                s.pop_back();
                sort(x.rbegin(),x.rend());
                if(c!=x[0]){
                    sort(x.begin(),x.end());
                    int cnt;
                    for(int i=0; i<x.size(); ++i){
                        if(x[i]==c)cnt=i+1;
                    }
                    cout<<s<<x[cnt]<<endl;
                    return 0;
                }
            }
        }
    }
}
