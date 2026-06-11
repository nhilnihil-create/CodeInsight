#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
int main(){
    vector<int> s(3);
    rep(i,3){
        cin>>s[i];
    }
    int cnt=0;
    sort(s.begin(),s.end());
    if(s[0]%2==s[1]%2 && s[1]%2==s[2]%2){

        cnt=(s[1]-s[0])/2+s[2]-s[1];
    }else{
        if(s[0]%2==s[1]%2){
            cnt=(s[1]-s[0])/2+s[2]-s[1];
        }else if(s[1]%2==s[2]%2){
            s[2]++;s[1]++;
            cnt=(s[1]-s[0])/2+s[2]-s[1]+1;
        }else if(s[0]%2==s[2]%2){
            s[0]++;s[2]++;
            cnt=(s[1]-s[0])/2+s[2]-s[1]+1;
        }

    }
    cout<<cnt<<endl;
}