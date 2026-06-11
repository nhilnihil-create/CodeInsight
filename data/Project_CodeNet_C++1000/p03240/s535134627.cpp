#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    vector<int> xv;
    vector<int> yv;
    vector<int> hv;
    int si;
    for(int i=0;i<n;i++){
        int x,y,h;
        cin>>x>>y>>h;        
        xv.push_back(x);
        yv.push_back(y);
        hv.push_back(h);
        if(h>0) si=i;
    }
    int vnum=xv.size();
    ll ansh;
    int ansx;
    int ansy;
    for(int cx=0;cx<=100;cx++){
        for(int cy=0;cy<=100;cy++){
            bool flag=true;
            ll lasth=hv[si]+abs(xv[si]-cx)+abs(yv[si]-cy);;
            for(int i=0;i<vnum;i++){
                ll temph=hv[i]+abs(xv[i]-cx)+abs(yv[i]-cy);
                if(hv[i]>0){
                    if(lasth!=temph){
                    flag=false;
                    break;
                }
                }else{
                    if(temph-lasth<0){
                    flag=false;
                    break;
                    }
                }
                                
            }
            if(flag){
                ansh=lasth;
                ansx=cx;
                ansy=cy;
                cout<<ansx<<" "<<ansy<<" "<<ansh<<endl;
                return 0;
            }
        }
    }        
}