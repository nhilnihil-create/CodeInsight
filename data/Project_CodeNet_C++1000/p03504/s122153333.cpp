#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>
#include <stack>
#include <map>
#include <functional>
#include <queue>
using namespace std;

int64_t min(int64_t a,int64_t b) {
    if (a > b)
    {
        return b ;
    }else
    {
        return a ;
    }
}


int main(){
    int n,c ;
    cin >> n >> c ;
    vector<pair<int,pair<int,int> > > p(n,pair<int,pair<int,int> >()) ;
    for (int i = 0; i < n; i++)
    {
        int ts,tt,tc ;
        cin >> ts >> tt >> tc ;
        p.at(i).first = tc ;
        p.at(i).second.first = ts ;
        p.at(i).second.second = tt ;
    }
    sort(p.begin(),p.end()) ;
    vector<pair<int,pair<int,int> > > truep(0,pair<int,pair<int,int> >()) ;
    pair<int,pair<int,int> > next = p.at(0) ;
    for (int i = 1; i < n; i++)
    {
        if (p.at(i).first == next.first && p.at(i).second.first == next.second.second)
        {
            next.second.second = p.at(i).second.second ;
        }else
        {
            truep.push_back(next) ;
            next = p.at(i) ;
        }
        
        
    }
    truep.push_back(next) ;
    vector<vector<int> > table(c+1,vector<int>(200001,0)) ;
    int ans = 0 ;
    for (int i = 0; i < truep.size(); i++)
    {
        table.at(truep.at(i).first).at(truep.at(i).second.first*2-1) = 1 ;
        table.at(truep.at(i).first).at(truep.at(i).second.second*2) = -1 ; 
    }
    int temp = 0 ;
    for (int i = 0; i < 200001; i++)
    {
        for (int channel = 0; channel < c+1; channel++)
        {
            temp += table.at(channel).at(i) ;
        }
        ans = max(temp,ans) ;
    }
    cout << ans << endl ;

}