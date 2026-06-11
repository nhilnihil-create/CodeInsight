#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    if(n!=26){
        set<char>se;
        rep(i,n){
            se.insert(s[i]);
        }
        for(char i='a'; i<='z'; ++i){
            if(se.find(i)==se.end()){
                cout<<s<<i<<endl;
                return 0;
            }
        }
    }
    else{
        if(s=="zyxwvutsrqponmlkjihgfedcba"){
            cout<<-1<<endl;
            return 0;
        }
        else{
            vector<char>c;
            c.push_back(s[n-1]);
            for(int i=n-2; i>=0; --i){
                sort(c.rbegin(),c.rend());
                if(c[0]<s[i]){
                    c.push_back(s[i]);
                }
                else{
                    c.push_back(s[i]);
                    sort(c.begin(),c.end());
                    cout<<s.substr(0,i)+c[lower_bound(c.begin(),c.end(),s[i])-c.begin()+1]<<endl;
                    return 0;
                }
            }
        }
    }
}