#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int ans1,ans2;
int main(void){
    string s; cin>>s;
    for(int i=0;i<s.size();i++){
        if(i%2==0){
            if(s[i]!='0'){
                ans1++;
            }
        }else{
            if(s[i]=='0'){
                ans1++;
            }
        }
    }
    for(int i=0;i<s.size();i++){
        if(i%2==0){
            if(s[i]=='0'){
                ans2++;
            }
        }else{
            if(s[i]!='0'){
                ans2++;
            }
        }
    }
    cout<<min(ans1,ans2)<<endl;

}

