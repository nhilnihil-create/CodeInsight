#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int d;
    cin>>d;
    map<int,string> mp;
    mp[25]="Christmas";
    mp[24]="Christmas Eve";
    mp[23]="Christmas Eve Eve";
    mp[22]="Christmas Eve Eve Eve";
    cout<<mp[d]<<endl;
}