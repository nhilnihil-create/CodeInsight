#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll GCD(ll a, ll b){ return a ? GCD(b % a, a) : b; }
int main(){
    string s;
    cin>>s;
    ll ans=0;
    vector<int> bw;
    int size=0;
    bool b=(s[0]=='B');
    int ssize=s.size();
    int i=0;
    while(i<ssize){
        int cnt=0;
        int j=i;
        for(j; j<ssize; j++){
            if(s[j]=='B' && b) cnt++;
            else if(s[j]=='W' && !b) cnt++;
            else{
                break;
            }
        }
        bw.push_back(cnt);
        size++;
        b=!b;
        i=j;
    }
    i=0;
    ll bcnt=0;
    if(s[0]=='W') i++;
    for(i; i+1<size; i+=2){
        bcnt+=bw[i];
        ans+=bcnt*bw[i+1];
    }

    cout<<ans<<endl;
}