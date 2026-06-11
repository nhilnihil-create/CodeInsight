#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;


typedef pair<int,int> pa;

set<string>s;

vector<string>ve;
unordered_map<string,int>mp;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    string ss;cin>>ss;
    int len=ss.size();
    for(int i=0;i<len;i++){
            string kk="";
        for(int j=i;j<min(len,i+10);j++){
             kk.push_back(ss[j]);
            if(!mp[kk]){
                mp[kk]=1;
                ve.push_back(kk);
            }
        }
    }
    sort(ve.begin(),ve.end(),less<string>());
    int k;cin>>k;
    cout<<ve[k-1]<<endl;
    return 0;
}
