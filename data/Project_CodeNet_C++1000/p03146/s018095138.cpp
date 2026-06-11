#include<bits/stdc++.h>
using namespace std;
int fun(int n){
    if(n%2==0){
        return n/2;
    }
    else{
        return 3*n+1;
    }
}
int main(){
    int s;
    cin>>s;
    set<int> ans;
    ans.insert(s);
    int n=s,i;
    for(i=0;i!=ans.size();i++){
        ans.insert(fun(n));
        n=fun(n);
    }
    cout<<i+1<<endl;
}