#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    string s;
    cin>>s;
    int ans=0;
    int i=0,j=s.size()-1;
    while(i<j){
        if(s[i]==s[j]) i++,j--;
        else if(s[i]=='x') ans++,i++;
        else if(s[j]=='x') ans++,j--;
        else{
            cout<<-1<<endl;
            return 0;
        }
    }

    cout<<ans<<endl;
}