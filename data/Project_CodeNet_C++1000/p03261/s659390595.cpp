#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep3(i, n) for (int i = 1; i < (int)(n+1); i++)
#define rep4(i, s, n) for (int i = (s); i < (int)(n+1); i++)
#define repr(i,n) for (int i = (n-1); i>=0;i--)
#define repr2(i,s,n) for (int i = (n-1); i>=(int)(s);i--)
#define repr3(i,n) for(int i = (n);i>0;i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
using Grid = vector<vector<int>>;
const ll INF = 10011032323450010;
const ld PI = 3.14159265358979323846;



int main() {
    int N;
    string pre ,now;
    bool judge=true;
    string S[101];
    map<string,int> word;
    cin>>N;
    rep(i,N){
        cin>>S[i];
        word[S[i]]++;
    }
    rep2(i,1,N){
        if(S[i][0]!=S[i-1][S[i-1].size()-1]){
            judge=false;
        }
        if(word[S[i]]>1){
            judge=false;
        }
        
    }
    if(judge){
        cout<<"Yes"<<endl;

    }
    else{
        cout<<"No"<<endl;
    }



return 0;
}