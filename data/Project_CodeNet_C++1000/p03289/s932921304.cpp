#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    string s;cin>>s;
    if(s[0]!='A'){co("WA");return 0;}
    int ccnt=0;
    for(int i=2;i<s.size()-1;i++){
        if(s[i]=='C')ccnt++;
    }
    if(ccnt!=1){co("WA");return 0;}
    int ucnt=0;
    rep(i,s.size()){
        if(isupper(s[i]))ucnt++;
    }
    if(ucnt!=2){co("WA");return 0;}
    co("AC");
}