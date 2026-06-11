#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(ll i=(j);i<(n);++i)
#define rrep(i,n) for(int i=(n);i>=0;--i)
#define ssort(n) sort((n).begin(),(n).end())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define NG cout <<"UNRESTORABLE" << endl;

#define INF 10101010

int main()
{
    string s;
    string t;
    cin >> s;
    cin >> t;

    bool result=false;
    int i=0;
    int j=0;
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    while(s[i]!='\0'){
        j=0;
        if(s[i]==t[j]||s[i]=='?'){
            while(t[j]!='\0'){
                if(s[i+j]==t[j]||s[i+j]=='?'){
                    ++j;
                }else{
                    break;
                }
            }
            if(t[j]=='\0'){
                rep(k,j){
                    s[i+k]=t[k];
                }
                result=true;
                break;
            }
        }
        ++i;
    }
    i=0;
    while(s[i]!='\0'){
        if(s[i]=='?'){
            s[i]='a';
        }
        ++i;
    }
    reverse(s.begin(),s.end());
    if(result){
        cout << s << endl;
    }else{
        NG;
    }
}