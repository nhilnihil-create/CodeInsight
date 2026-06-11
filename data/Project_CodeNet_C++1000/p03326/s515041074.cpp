    #include <iostream>
    #include <vector>
    #include <cmath>
    #include <limits.h>
    #include <utility>
    #include <map>
    #include <algorithm>
    #include <set>
    using namespace std;
    using P = pair<int,int>;
    using ll = long long;
    const int MOD=1e9+7;
    int main(){
        int n,m;
        cin>>n>>m;
        vector<ll> x(n),y(n),z(n),s(n);
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i]>>z[i];
        }
        ll ret=0;
        for(int a=-1;a<=1;a+=2){
            for(int b=-1;b<=1;b+=2){
                for(int c=-1;c<=1;c+=2){
                    for(int i=0;i<n;i++)s[i]=x[i]*a+y[i]*b+z[i]*c;
                    sort(s.rbegin(),s.rend());
                    ll cnt=0;
                    for(int i=0;i<m;i++){
                        cnt+=s[i];
                    }
                    ret=max(ret,cnt);
                }
            }
        }
        cout<<ret<<endl;
        return(0);
    }