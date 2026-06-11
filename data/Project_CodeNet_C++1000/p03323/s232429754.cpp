#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>

using namespace std;


#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
int main() {
   /* map<int,pair<int,int>> mp;
    int n,m,problem;
    string s;
    cin >>n>>m;
    for(int i=0;i<m;i++){
        cin>>problem;
        cin >> s;
        if(s=="AC")mp[problem].first=1;
        else{
            if(mp[problem].first==0) mp[problem].second++;
        }
    }
    int ACs=0,WAs=0;
    for(auto i=mp.begin();i!=mp.end();i++){
        ACs+=i->second.first;
        WAs+=i->second.second;
    }
    cout << ACs <<" "<<WAs;*/

    int a,b;
    cin >>a>>b;
    if(max(a,b)<= (16-max(a,b))) cout <<"Yay!";
    else cout <<":(";


    return 0;


}
