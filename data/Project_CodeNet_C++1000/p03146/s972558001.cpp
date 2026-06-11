#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int s,ans=0;
    cin>>s;
    map<int,bool>a;
    stack<int>st;
    
    st.push(s);
    a[s]=true;
    
    int i=1;
    while(ans==0){
        int n=st.top();
        int fn;
        if(n&1)fn=3*n+1;
        else fn=n/2;
        
        i++;
        if(a[fn])ans=i;
        st.pop();
        st.push(fn);
        a[fn]=true;
    }
    cout<<ans<<endl;
    return 0;
}