#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int in() {int x; cin>>x; return x;}
ll lin() {ll x; cin>>x; return x;}
string sin() {string x;cin>>x;return x;}
using graph = vector<vector<int>>;
using graph2 = vector<vector<pair<int, int>>>;

int main(){
    int N=in();
    int d[24];
    rep(i, 24){
        d[i]=0;
    }
    d[0]=1;
    int a;
    rep(i, N){
        cin>>a;
        d[a]++;
    }
    int check=0;
    int cnt=0;
    vector<int> Q;
    vector<int> S;
    rep(i, 13){
        if(i==0||i==12){
            if(d[i]>1){
                check=1;
                cout<<0<<endl;
                break;
            }
            else if(d[i]==1){
                Q.push_back(i);
            }
        }
        else{
            if(d[i]>2){
                check=1;
                cout<<0<<endl;
                break;
            }
            else if(d[i]==1){
                S.push_back(i);
            }
            else if(d[i]==2){
                Q.push_back(i);
                Q.push_back(24-i);
            }
        }
    }
    vector<int> U;
    int ans=0;
    int m;
    sort(S.begin(), S.end());
    if(check==0){
        if(S.size()>1){
            for(int bit=0;bit<(1<<S.size()-1);bit++){
                U=Q;
                U.push_back(S.at(0));
                rep(i, S.size()-1){
                    if(bit>>i&1){
                        U.push_back(24-S.at(i+1));
                    }
                    else{
                        U.push_back(S.at(i+1));
                    }
                }
                sort(U.begin(), U.end());
                m=100;
                rep(i, U.size()-1){
                    m=min(m, U.at(i+1)-U.at(i));
                }
                ans=max(ans, m);
            }
        }
        else if (S.size()==1){
            U=Q;
            U.push_back(S.at(0));
            sort(U.begin(), U.end());
            m=100;
            rep(i, U.size()-1){
                m=min(m, U.at(i+1)-U.at(i));
            }
            ans=max(ans, m);
        }
        else{
            U=Q;
            sort(U.begin(), U.end());
            m=100;
            rep(i, U.size()-1){
                m=min(m, U.at(i+1)-U.at(i));
            }
            ans=max(ans, m);
        }
        cout<<ans<<endl;
    }
}