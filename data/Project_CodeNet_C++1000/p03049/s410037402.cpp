#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int in() {int x; cin>>x; return x;}
ll lin() {ll x; cin>>x; return x;}
string sin() {string x;cin>>x;return x;}
using graph = vector<vector<int>>;
using graph2 = vector<vector<pair<int, int>>>;

bool ifprime(int x){
    if(x==1)return false;
    if(x==2)return true;
    if(x%2==0)return false;
    for(int i=2;i*i<=x;i++){if(x%i==0)return false;}
    return true;
}
ll mod(ll x, ll y){if(x>=0||x%y==0) return x%y;return y+x%y;} //mod including minus
ll dv0(ll x, ll y){if(x>=0||x%y==0)return x/y;return x/y-1;} //rnd down
ll dv1(ll x, ll y){if(x%y==0) return dv0(x,y);return dv0(x,y)+1;} //rnd up

//Start from Here
int main(){
    int N=in();
    string S;
    int a=0, b=0, c=0;
    int cnt=0;
    rep(i, N){
        cin>>S;
        rep(j, S.size()-1){
            if(S.at(j)=='A'&&S.at(j+1)=='B'){
                cnt++;
            }
        }
        if(S.at(0)=='B'&&S.at(S.size()-1)=='A'){
            c+=1;
        }
        else if(S.at(S.size()-1)=='A'){
            a+=1;
        }
        else if(S.at(0)=='B'){
            b+=1;
        }
    }
    if(a>0||b>0||c==0){
        cout<<cnt+c+min(a, b)<<endl;
    }
    else if(c>0){
        cout<<cnt+c-1<<endl;
    }
}