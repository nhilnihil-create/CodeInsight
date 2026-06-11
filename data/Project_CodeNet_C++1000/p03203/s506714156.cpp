#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<int,int> P;

int main(){
    int i,j;
    int h,w,n;
    cin>>h>>w>>n;
    vector<P> v;

    for(i=0;i<n;i++) {
        int x,y;
        cin>>x>>y;
        v.pb(P(x,y));
    }
    sort(v.begin(),v.end());

    int temp=0;
    for(i=0;i<v.size();i++){
        if(v[i].fi>=v[i].se+temp) {
            if(v[i].fi>=v[i].se+temp+1) {
                cout<<v[i].fi-1<<endl;
                return 0;
            }
            else temp++;
        }
    }
    cout<<h<<endl;
    return 0;
}