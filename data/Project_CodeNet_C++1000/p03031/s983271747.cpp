#include <bits/stdc++.h>
    #include <math.h>

    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    # define M_PI  3.14159265358979323846


    void solve(){
        int n,m;
        cin>>n>>m;
        vector<int>sw[n+1];
        for(int i=0;i<m;i++){
            int s;
            cin>>s;
            for(int j=0;j<s;j++){
                int x;
                cin>>x;
                --x;
                sw[x].push_back(i);
            }
        }
        vector<int>p(m);
        for(int i=0;i<m;i++)
            cin>>p[i];
        int total=0;
        for(int i=0;i<(int)(1<<n);i++){
            vector<int>bulb(m);
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    for(auto z : sw[j])
                        bulb[z]++;
                }
            }
            bool flag=true;
            for(int j=0;j<m;j++){
                if(bulb[j]%2!=p[j]){
                    flag=false;
                    break;
                }
            }
            if(flag)
                total++;
        }
        cout<<total;
    }
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cout<<fixed;
        cout<<setprecision(10);
        int t=1;
//        cin>>t;
        for(int i=1;i<=t;i++){
            solve();
        }
        return 0;
    }
