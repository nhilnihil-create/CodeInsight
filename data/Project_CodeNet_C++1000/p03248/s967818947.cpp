#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    if(s[n-1]=='1'||s[0]=='0'){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[n-2-i]){
            cout<<-1<<endl;
            return 0;
        }
    }
    int to=n-1;
    for(int i=n-2;i>=0;i--){
        cout<<i+1<<" "<<to+1<<endl;
        if(s[i]=='1')to=i;
    }
}
