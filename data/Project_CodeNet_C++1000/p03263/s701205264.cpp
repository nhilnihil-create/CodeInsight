#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;

int main(){
    int h,w;cin>>h>>w;
    vvin a(h,vin(w));
    rep(i,h)rep(j,w)cin>>a[i][j];
    queue<tuple<int,int,int,int>> ans;
    bool tmp=false;
    rep(i,h){
        if(i%2==0){
            rep(j,w){
                if(tmp){
                    if(a[i][j]%2==0){
                        tmp=false;
                        continue;
                    }
                    else{
                        if(j<w-1){
                            ans.push(make_tuple(i+1,j+1,i+1,j+2));
                            a[i][j]--;a[i][j+1]++;
                        }
                        else if(j==w-1&&i<h-1){
                            ans.push(make_tuple(i+1,j+1,i+2,j+1));
                            a[i][j]--;a[i+1][j]++;
                        }
                    }
                }
                if(!tmp&&a[i][j]%2){
                    if(j<w-1){
                        ans.push(make_tuple(i+1,j+1,i+1,j+2));
                        a[i][j]--;a[i][j+1]++;
                    }
                    else if(j==w-1&&i<h-1){
                        ans.push(make_tuple(i+1,j+1,i+2,j+1));
                        a[i][j]--;a[i+1][j]++;
                    }
                    tmp=true;
                }
            }
        }
        else{
            for(int j=w-1;j>=0;j--){
                if(tmp){
                    if(a[i][j]%2==0){
                        tmp=false;
                        continue;
                    }
                    else{
                        if(j>0){
                            ans.push(make_tuple(i+1,j+1,i+1,j));
                            a[i][j]--;a[i][j-1]++;
                        }
                        else if(j==0&&i<h-1){
                            ans.push(make_tuple(i+1,j+1,i+2,j+1));
                            a[i][j]--;a[i+1][j]++;
                        }
                    }
                }
                if(!tmp&&a[i][j]%2){
                    if(j>0){
                        ans.push(make_tuple(i+1,j+1,i+1,j));
                        a[i][j]--;a[i][j-1]++;
                    }
                    else if(j==0&&i<h-1){
                        ans.push(make_tuple(i+1,j+1,i+2,j+1));
                        a[i][j]--;a[i+1][j]++;
                    }
                    tmp=true;
                }
            }
        }
    }
    cout<<ans.size()<<endl;
    while(ans.size()){
        auto p=ans.front();ans.pop();
        cout<<get<0>(p)<<" "<<get<1>(p)<<" "<<get<2>(p)<<" "<<get<3>(p)<<endl;
    }
}