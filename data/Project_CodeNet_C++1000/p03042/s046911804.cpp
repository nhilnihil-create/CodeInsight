#include <bits/stdc++.h>
    #include <math.h>

    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    # define M_PI  3.14159265358979323846


    void solve(){
        string s;
        cin>>s;
        string s1=s.substr(0,2);
        string s2=s.substr(2,2);
        int x=stoi(s1);
        int y=stoi(s2);
        int ans=0;
        if(x>=1 && x<=12)
            ans++;
        if(y>=1 && y<=12)
            ans+=2;
        if(ans==1)
            cout<<"MMYY";
        else if(ans==2)
            cout<<"YYMM";
        else if(ans==3)
            cout<<"AMBIGUOUS";
        else
            cout<<"NA";
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
