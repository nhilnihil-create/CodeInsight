#include<bits/stdc++.h>
using namespace std;
int main() {
//string s,t;
int a,b,c,i,n,t;
long double g,h,o;
    map<int,int> ma;
    map<int,int> :: iterator it;
vector<int> v;
cin>>n>>t;
for(i=1;i<=n;i++){
    cin>>a>>b;
    if(b<=t){
        ma[a] = 1;
    }
}
if(ma.size()==0){cout<<"TLE"<<endl;}
else {
    it = ma.begin();
        cout<<(*it).first<<endl;
}
}