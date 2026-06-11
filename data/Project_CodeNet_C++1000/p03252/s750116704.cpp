#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using Graph=vector<vector<int>>;

int main(){
    string S,T;
    cin>>S>>T;
    int N=S.size();
    vector<int>change(26,-1);
    vector<int>change2(26,-1);
    bool flag=true;
    rep(i,N){
        int A=S.at(i)-'a';
        int B=T.at(i)-'a';
        if(change[A]==-1){
            change[A]=B;
        }
        else{
            if(change[A]!=B){
                flag=false;
            }
        }
    }
    rep(i,N){
        int A=S.at(i)-'a';
        int B=T.at(i)-'a';
        if(change2[B]==-1){
            change2[B]=A;
        }
        else{
            if(change2[B]!=A){
                flag=false;
            }
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}