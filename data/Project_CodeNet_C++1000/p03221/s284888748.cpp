#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <ios>
#include <iomanip>
#define ll long long
using namespace std;
typedef pair<ll,int> P;

int main(){
    int n,m;
    cin>>n>>m;
    vector<P> city;
    vector<int> pref(m);
    for(int i=0;i<m;i++){
        int y;
        cin>>pref[i]>>y;
        city.emplace_back(y,i);
    }
    sort(city.begin(),city.end());
    vector<int> chkpref(100005);
    vector<P> citynum;
    for(int i=0;i<m;i++){        
        chkpref[pref[city[i].second]]++;
        citynum.emplace_back(city[i].second,chkpref[pref[city[i].second]]);
    }
    sort(citynum.begin(),citynum.end());
    for(int i=0;i<m;i++){
        cout<<setfill('0')<<right<<setw(6)<<pref[citynum[i].first];
        cout<<setfill('0')<<right<<setw(6)<<citynum[i].second;
        cout<<endl;
    }
    return 0;
}