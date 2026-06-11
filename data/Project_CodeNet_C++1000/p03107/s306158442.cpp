#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    string s;
    cin>>s;
    int ans=0;
    for(i=0;i<s.length();){
        cerr<<"i:"<<i<<endl;
        if((s[i]=='0'&&s[i+1]=='1')||(s[i]=='1'&&s[i+1]=='0')){
            s.erase(s.begin()+i);
            s.erase(s.begin()+i);
            if(i!=0)i--;
            ans+=2;
        }else{
            i++;
        }
    }
    cout<<ans<<endl;
}