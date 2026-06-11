//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;


int main(){
    string s; cin>>s;
    if(s[0]!='A'){
        cout<<"WA"<<endl;
        return 0;
    }
    ll cnt=0;
    ll c;
    for(int i=2;i<=s.size()-2;i++){
        if(s[i]=='C'){
            cnt++;
            c=i;
        }
    }
    if(cnt!=1){
        cout<<"WA"<<endl;
        return 0;
    }
    for(int i=1;i<s.size();i++){
        if(i!=c){
            if(s[i]<='Z'&&'A'<=s[i]){
                cout<<"WA"<<endl;
                return 0;
            }
        }
    }
    cout<<"AC"<<endl;

}






