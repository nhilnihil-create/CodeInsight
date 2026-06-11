#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb push_back;
#define sp " ";
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    int d,g,point,ans=100000000;
    cin>>d>>g;
    vi p,c;
    rep(i,d){
        int pi,ci;
        cin>>pi>>ci;
        p.push_back(pi);
        c.push_back(ci);
    }
    rep(i,(1<<d)){
        int count=0;
        point=0;
        int rm;
        rep(j,d){
            if(i&(1<<j)){
                point+=p.at(j)*100*(j+1);
                point+=c.at(j);
                count+=p.at(j);
            }
            else{
                rm=j;
            }
        }
        if(point<g){
            int time=100*(rm+1);
            int need=(g-point+time-1)/time;
            if(need>=p.at(rm)){
                continue;
            }
            count+=need;
        }
        ans=min(ans,count);
    }
    cout<<ans;
}