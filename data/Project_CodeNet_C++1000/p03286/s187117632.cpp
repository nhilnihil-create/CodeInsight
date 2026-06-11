#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n; cin>>n;
    if(n==0){
        cout<<0<<endl;
        return 0;
    }    
    vector<int> ans;
    while(n){
        if(n>0){
            ans.push_back(n%(-2));
            n/=(-2);
        }
        else{
            int m=abs(n);
            if(m%2==1){
                m++; n=m/2; ans.push_back(1);
            }
            else{
                n=m/2; ans.push_back(0);
            }
        }
        //cout<<n<<" ";
    }
    reverse(btoe(ans));
    for(auto& v: ans) cout<<v;
    cout<<endl;
    return 0;
}