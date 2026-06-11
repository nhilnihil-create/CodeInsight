#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){

    string s;
    cin>>s;
    int n=s.length();
    unordered_map<char,int> m;
    m['A']=1;m['C']=1;m['G']=1;m['T']=1;
    int c=0,ans=0;
    for(int i=0;i<n;i++){
        if(m[s[i]]){
            c++;
        }
        else{
            c=0;
        }
        ans=max(ans,c);
    }
    cout<<ans;


return 0;
}
