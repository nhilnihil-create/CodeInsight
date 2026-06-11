#include<bits/stdc++.h>
using namespace std;

int n;
vector<string>d;

void dfs(string s,int cnt){
    if(cnt==n)d.push_back(s);
    else{
        cnt++;
        dfs(s+'0',cnt);
        dfs(s+'1',cnt);
        dfs(s+'2',cnt);
        dfs(s+'3',cnt);
    }
}

int main(){
    cin>>n;
    int a,b,c;cin>>a>>b>>c;
    vector<int>l(n);
    for(int i=0;i<n;++i)cin>>l[i];
    dfs("",0);
    sort(d.begin(),d.end());
    int ans=1e9;
    for(int i=0;i<d.size();++i){
        int la=0,lb=0,lc=0,lans=0,ca=0,cb=0,cc=0;
        for(int j=0;j<n;++j){
            if(d[i][j]=='0'){la+=l[j];ca++;}
            else if(d[i][j]=='1'){lb+=l[j];cb++;}
            else if(d[i][j]=='2'){lc+=l[j];cc++;}
        }
        if(ca==0||cb==0||cc==0)continue;
        lans+=10*(ca-1);
        lans+=10*(cb-1);
        lans+=10*(cc-1);
        lans+=abs(a-la)+abs(b-lb)+abs(c-lc);
        if(ans>lans){ans=lans;}
    }
    cout<<ans<<endl;
}