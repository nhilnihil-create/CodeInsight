#include<iostream>
#include<queue>
using namespace std;
int main(){
    string s;
    int x,y,i,j,r=0,cnt;
    cin>>s>>x>>y;
    queue<int>v,h;
    for(i=0;i<s.size()&&s[i]!='T';i++)r++;
    while(i<s.size()){
        for(cnt=0,i++;i<s.size()&&s[i]!='T';i++,cnt++);
        v.push(cnt);
        for(cnt=0,i++;i<s.size()&&s[i]!='T';i++,cnt++);
        h.push(cnt);
    }
    int vs=v.size(),hs=h.size();
    bool dpv[vs+1][16001]={},dph[hs+1][16001]={};
    dpv[0][8000]=true;
    for(i=0;i<vs;i++){
        cnt=v.front();v.pop();
        for(j=0;j<=16000;j++)if(dpv[i][j])dpv[i+1][j+cnt]=dpv[i+1][j-cnt]=true;
    }
    dph[0][8000+r]=true;
    for(i=0;i<hs;i++){
        cnt=h.front();h.pop();
        for(j=0;j<=16000;j++)if(dph[i][j])dph[i+1][j+cnt]=dph[i+1][j-cnt]=true;
    }
    cout<<(dph[hs][x+8000]&&dpv[vs][y+8000]?"Yes":"No")<<endl;
    return 0;
}