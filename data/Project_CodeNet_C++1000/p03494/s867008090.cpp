#include<bits/stdc++.h>
using namespace std;
bool jud(vector<int> a,int n){
    bool ans=false;
    for(int i=0;i<n;i++){
        if(a.at(i)%2==1){
            return ans;
        }
    }
    ans=true;
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a.at(i);
        if(a.at(i)%2==1){
            cout<<0<<endl;
            return 0;
        }
    }
    int cnt=0;
    while(jud(a,n)){
        cnt++;
        for(int i=0;i<n;i++){
            a.at(i)/=2;
        }
    }
    cout<<cnt<<endl;
}