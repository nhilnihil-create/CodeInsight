#include "bits/stdc++.h"
#define Rep(i,n) for(int i=0;i<n;i++)
#define For(i,n1,n2) for(int i=n1;i<n2;i++)
#define REP(i,n) for(ll i=0;i<n;i++)
#define FOR(i,n1,n2) for(ll i=n1;i<n2;i++)
#define put(a) cout<<a<<endl;
#define all(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define TDARRAY(int,a,n,m) vector<vector<int>> a(n,vector<int>(m,0));
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) {if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a, T b) {if(a>b){a=b;return 1;}return 0;}

int n;
vector<int> e24(int c){
    int cnt=0;
    int i=0;
    vector<int> rtn(c);
    while(cnt<c){
        if(i%3){
            rtn[cnt]=i*2;
            cnt++;
        }
        i++;
    }
    return rtn;
}
vector<int> e6(int c){
    int cnt=0;
    int i=1;
    vector<int> rtn(c);
    while(cnt<c){
        rtn[cnt]=i*6;
        cnt++;
        i++;
    }
    return rtn;
}

vector<int> o3(int c){
    int cnt=0;
    int i=4;
    vector<int> rtn(c);
    while(cnt<c){
        if(i%2){
            rtn[cnt]=i*3;
            cnt++;
        }
        i++;
    }
    return rtn;
}
int main(){
    cin >> n;
    if(n>3){
        vector<int> res;
        
        res.push_back(3);
        res.push_back(9);
        n-=2;
        if(n<=10001){
            if(n%2!=0){
                res.push_back(6);
                n--;
            }
            vector<int> e = e24(n);
            REP(i,e.size()){
                res.push_back(e[i]);
            }
        }else if(n<=15000){
            vector<int> e=e24(10000);
            n-=10000;
            vector<int> e2=e6(n);
            REP(i,e.size()){
                res.push_back(e[i]);
            }
            REP(i,e2.size()){
                res.push_back(e2[i]);
            }
        }else{
            vector<int> e=e24(10000);
            REP(i,e.size()){
                res.push_back(e[i]);
            }
            n-=10000;
            if(n%2==0){
                vector<int> e2=e6(5000);
                REP(i,e2.size()){
                    res.push_back(e2[i]);
                }
                n-=5000;
            }else{
                vector<int> e2=e6(5000-1);
                REP(i,e2.size()){
                    res.push_back(e2[i]);
                }
                n-=5000-1;
            }
            vector<int> o=o3(n);
            REP(i,o.size()){
                res.push_back(o[i]);
            }
            
        }
        REP(i,res.size()){
            cout << res[i] << " ";
        }
        put("");
    }else{
        put("2 5 63");
    }
    return 0;
}
