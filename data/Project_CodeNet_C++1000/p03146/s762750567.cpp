#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    long long int s;
    cin>>s;
    set<int>st;
    int x=s;
    while(st.count(x)==0){
        st.insert(x);
        if(x%2==0){
            x/=2;
        }
        else x=x*3+1;
    }
    cout<<st.size()+1<<endl;
}
    
    

