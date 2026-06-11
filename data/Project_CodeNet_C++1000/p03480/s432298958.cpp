#include<bits/stdc++.h>
using namespace std;
typedef signed long long int ll;
#define ALL(a)  (a).begin(),(a).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)


int main(){
    string s;
    cin>>s;
    
    int n=(int)s.size();
    int ans=n;
    rep(i,n-1){
        if(s[i]!=s[i+1]){
            int tmp;
            tmp=max(i+1,n-i-1);
            ans=min(ans,tmp);
        }
    }
    
    cout<<ans<<endl;
    return 0;
}
