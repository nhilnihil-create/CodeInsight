#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=9999999999;
int a[510][510];


int main(){
    int h,w;
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int b;
            cin>>b;
            b%=2;
            a[i][j]=b;
        }
    }
    vector<PP> ans;
    bool f=true;
    for(int i=0;i<h;i++){
        if(i%2==0){
            for(int j=0;j<w;j++){
                if(a[i][j]){
                    if(f){
                        if(j<w-1){
                            ans.push_back(PP(P(i,j),P(i,j+1)));
                        }else if(i<h-1){
                            ans.push_back(PP(P(i,j),P(i+1,j)));
                        }    
                        f=false;
                    }else{
                        f=true;
                    }
                }else{
                    if(!f){
                        if(j<w-1){
                            ans.push_back(PP(P(i,j),P(i,j+1)));
                        }else if(i<h-1){
                            ans.push_back(PP(P(i,j),P(i+1,j)));
                        }    
                    }
                }
            }
        }else{
            for(int j=w-1;j>=0;j--){
                if(a[i][j]){
                    if(f){
                        if(j>0){
                            ans.push_back(PP(P(i,j),P(i,j-1)));
                        }else if(i<h-1){
                            ans.push_back(PP(P(i,j),P(i+1,j)));
                        }    
                        f=false;
                    }else{
                        f=true;
                    }
                }else{
                    if(!f){
                        if(j>0){
                            ans.push_back(PP(P(i,j),P(i,j-1)));
                        }else if(i<h-1){
                            ans.push_back(PP(P(i,j),P(i+1,j)));
                        }    
                    }
                }
            }
        }
    }
    cout<<ans.size()<<endl;
    for(PP pp:ans){
        int q=pp.first.first+1;
        int w=pp.first.second+1;
        int e=pp.second.first+1;
        int r=pp.second.second+1;
        cout<<q<<" "<<w<<" "<<e<<" "<<r<<endl;
    }

}