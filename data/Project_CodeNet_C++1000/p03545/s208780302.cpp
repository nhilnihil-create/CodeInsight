#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    string s;
    cin>>s;
    int a[4];
    rep(i,4)a[i]=s[i]-'0';
    for(int bit=0; bit<(1<<3); ++bit){
        int sum=a[0];
        rep(i,3){
            if(bit&(1<<i))sum+=a[i+1];
            else sum-=a[i+1];
        }
        if(sum==7){
            cout<<a[0];
            rep(i,3){
                if(bit&(1<<i))cout<<'+';
                else cout<<'-';
                cout<<a[i+1];
            }
            cout<<"=7"<<endl;
            return 0;
        }
    }
}