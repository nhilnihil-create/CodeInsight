#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;n>i;++i)
using namespace std;
using ll=int64_t;
using vi=vector<int>;
using VI=vector<ll>;
using vis=vector<string>;
using vvi=vector<vi>;
int main(){
    string s;
    cin>>s;
    if(s=="A"){
        cout<<"T"<<endl;
        return 0;
    }
    if(s=="T"){
        cout<<"A"<<endl;
        return 0;
    }
    if(s=="G"){
        cout<<"C"<<endl;
        return 0;
    }
    if(s=="C"){
        cout<<"G"<<endl;
        return 0;
    }
}