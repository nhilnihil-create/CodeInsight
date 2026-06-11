#include <bits/stdc++.h>
using namespace std;;
#define ll long long
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
int main(){
    string s; cin >> s;
    int xx , yy; cin >> xx >> yy;
    vector<int> x,y;
    bool nowx = true;
    int count =0;
    int tcount = 0;
    bool minusx=false;
    REP(i,s.length()){
        if(nowx){
            if(s[i]=='F'){
                if(tcount!=0&&x.size()==0){
                    minusx = true;
                }
                count++;
                if(i==s.size()-1){
                    x.push_back(count);
                }
            }else{
                tcount++;
                if(count!=0){
                    x.push_back(count);
                    count =0;
                }
                nowx = false;
            }
        }else{
            if(s[i]=='F'){
                count++;
                if(i==s.size()-1){
                    y.push_back(count);
                }
            }else{
                tcount++;
                if(count!=0){
                    y.push_back(count);
                    count =0;
                }
                nowx = true;
            }
        }
    }
    bool ansx, ansy ;
    if(x.size()!=0 ){
        set<int> xdp[x.size()];
        xdp[0].insert(x[0]);
        if(minusx)xdp[0].insert(-x[0]);
        REP(i,x.size()-1){
            auto it = xdp[i].begin();
            while(it!=xdp[i].end()){
                xdp[i+1].insert(*it+x[i+1]);
                xdp[i+1].insert(*it-x[i+1]);
                it++;
            }
        }
       if(xdp[x.size()-1].count(xx)==1){
            ansx = true;
        }else{
            ansx = false;
        }
    }else{
        if(xx==0){
            ansx = true;
        }else{
            ansx = false;
        }

    }
    if(y.size()!=0){
        set<int> ydp[y.size()];
        ydp[0].insert(y[0]);
        ydp[0].insert(-y[0]);
        REP(i,y.size()-1){
            auto it = ydp[i].begin();
            while(it!=ydp[i].end()){
                ydp[i+1].insert(*it+y[i+1]);
                ydp[i+1].insert(*it-y[i+1]);
                it++;
            }
        }
       if(ydp[y.size()-1].count(yy)==1){
            ansy = true;
        }else{
            ansy = false;
        }
    }else{
        if(yy==0){
            ansy = true;
        }else{
            ansy = false;
        }
    }
    if(ansx && ansy){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}