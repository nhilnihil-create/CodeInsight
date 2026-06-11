#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
const int INF=1000000000;

int main(){
    string S;cin>>S;
    string a[16]={"AKIHABARA","AKIHABAR","AKIHABRA","AKIHBARA","KIHABARA","AKIHABR","AKIHBAR","AKIHBRA",
                "KIHABAR","KIHABRA","KIHBARA","AKIHBR","KIHABR","KIHBAR","KIHBRA","KIHBR"};
    rep(i,16){
        if(S==a[i]){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}