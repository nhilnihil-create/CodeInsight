#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    string s,t={"keyence"};
    cin>>s;
    int a=s.size()-7;
    for(int i=0;i<s.size()-a;i++){
        int c=0;
        for(int j=0;j<s.size();j++){
            if(i>j || j>=i+a){
                if(s[j]==t[c]){
                    c++;
                }
            }
        }
        if(c==7){
            cout<<"YES"<<endl;
            return(0);
        }
    }
    cout<<"NO"<<endl;
    return(0);
}