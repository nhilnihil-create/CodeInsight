#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1000000007;

int main(){
    string seireki;
    cin>>seireki;
    bool ifreiwa=true;
    string y,m,d;
    y=seireki.substr(0,4);
    m=seireki.substr(5,2);
    d=seireki.substr(8,2);
    //cout<<y<<" "<<m<<" "<<d<<endl;
    if(y<"2019") ifreiwa=false;
    else if(y=="2019"){
        if(m<"04") ifreiwa=false;
        else if(m=="04"){
            if(d<="30") ifreiwa=false;
        }
    }
    if(ifreiwa) cout<<"TBD"<<endl;
    else cout<<"Heisei"<<endl;
    return 0;
}