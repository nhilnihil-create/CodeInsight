#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
using namespace std;
typedef long long ll;

int main(){
    int n;string s;cin>>n>>s;
    vector< pair <int,int> > v(n);
    int b=0,w=0;
    for(int i=0;i<n;i++){
        if(s[i]=='.')w++;
        else b++;
        v[i]=make_pair(w,b);
    }
    int ans=1e6;
    for(int i=0;i<n;i++){
        int yay=v[i].second+v[n-1].first-v[i].first;
        ans=min(ans,yay);
    }
   ans=min(ans,v[n-1].first);
    cout<<ans;
}