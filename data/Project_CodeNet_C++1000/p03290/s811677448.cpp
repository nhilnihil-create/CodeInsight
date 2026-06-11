#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
 
    int d,g;
    cin>>d>>g;
    vector<int>p(d);
    vector<int>c(d);
    rep(i,d)cin>>p[i]>>c[i];
    int min_c=1e9;
    for(int bit=0;bit<(1<<d);++bit){
        int get_score=0,cnt=0,max=-1;
        rep(i,d){
            if(bit&(1<<i)){
                get_score+=100*(i+1)*p[i]+c[i];
                cnt+=p[i];
            }
            else{
                max=i;
            }
        }
        if(get_score<g){
            int p_cnt=0;
            int x=(g-get_score-1+100*(max+1))/(100*(max+1));
            if(x>p[max])cnt=1e9;
            else cnt+=x;
        }
        min_c=min(min_c,cnt);
    }
    cout<<min_c<<endl;
 
    return 0;
}
