#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m; i < n; i++) 
#define mod 1000000007
#define pi 3.1415926535
typedef long long ll;
int main(){
    int N;
    string S;
    cin>>N>>S;
    int count=0;
    int ma=0;
    
    FOR(i,1,S.size()){
        string t=S.substr(0,i);
        string u=S.substr(i);
        set<char>s1;
        set<char>s2;
        set<char>s3;
        //cout<<t<<" "<<u<<endl;

        rep(j,t.size()){
            s1.insert(t[j]);
        }

        rep(j,u.size()){
            s2.insert(u[j]);
        }

        set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(s3,s3.end()));
        //s1とs2の積集合をs3に入れる
        
        ma=max((int)s3.size(),ma);
    }
        cout<<ma<<endl;
    return 0;
}