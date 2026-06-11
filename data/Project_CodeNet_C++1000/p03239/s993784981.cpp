#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,T;
    cin>>n>>T;
    vector<int> c(n),t(n);
    priority_queue<int> min;
    for(int i=0;i<n;i++){
        cin>>c.at(i)>>t.at(i);
        if(t.at(i)<=T)
        min.push(c.at(i));
    }
    if(min.size()==0){
        cout<<"TLE"<<endl;
        return 0;
    }
    while(min.size()>1){
        min.pop();
    }
    cout<<min.top()<<endl;
}