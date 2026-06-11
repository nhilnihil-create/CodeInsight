#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

#define INF (1ll<<60)

int main(int argc, char const *argv[]) {
    int n;cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int ll=0,r=n;
    while(r>ll+1){
        int m = (ll+r)/2;
        map<long long, int> ma;
        long long l=0;
        bool b = true;
        if(m==1){
            for(int i=0;i<n-1;++i){
                if(a[i+1]<=a[i])b=false;
            }
        }
        else{
            for(int i=0;i<n;++i){
                int aa = a[i];
                if(aa<=l){
                    vector<long long> tmp(0);
                    // auto itr = ma.upper_bound(l);
                    for(auto itr=ma.end();itr!=ma.begin();){
                        itr--;
                        if((itr->first)>aa)tmp.push_back(itr->first);
                        else break;
                    }
                    for(auto i:tmp)ma.erase(i);
                    while(aa>1&&ma.find(aa)!=ma.end()&&ma[aa]>=m-1){
                        ma.erase(aa);
                        aa--;
                    }
                    if(ma.find(aa)!=ma.end()&&ma[aa]>=m-1){
                        b=false;
                        break;
                    }
                    else{
                        if(ma.find(aa)!=ma.end())ma[aa]++;
                        else ma[aa]=1;
                    }
                }
                l = a[i];
            }
        }
        if(b)r=m;
        else ll=m;
    }
    cout<<r<<endl;
    return 0;
}