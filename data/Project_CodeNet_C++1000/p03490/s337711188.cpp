#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string s;
int x,y;
vector<int>vx,vy;
int dp[4010][16010];

void make(int z,int n){
    for(int i=0;i<=16010;++i){
        if(i==z)dp[0][i]=1;
        else dp[0][i]=0;
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<=16010;++j)dp[i][j]=-1;
    }
}


int cal(int n,int z, int i){
    if(z>16000||z<0)return 0;
    if(n==0)return dp[0][z];
    if(dp[n][z]!=-1)return dp[n][z];
    if(i==0)return dp[n][z]=max(cal(n-1,z+vx[n-1],0),cal(n-1,z-vx[n-1],0));
    else return dp[n][z]=max(cal(n-1,z+vy[n-1],1),cal(n-1,z-vy[n-1],1));
}


int main(){
    cin>>s;
    cin>>x>>y;

    int p=0,cnt=0;
    for(int i=0;i<s.length();++i){
        if(s[i]=='T'){
            if(p==0)vx.push_back(cnt);
            else vy.push_back(cnt);
            cnt=0;
            p++;
            p%=2;
        }
        else{
            cnt++;
        }
    }
    if(p==0)vx.push_back(cnt);
    else vy.push_back(cnt);

    make(vx[0]+8000,vx.size()-1);
    reverse(vx.begin(),vx.end());
    vx.pop_back();
    reverse(vx.begin(),vx.end());
    int a=cal(vx.size(),x+8000,0);
    //cout<<a<<endl;
    

    make(8000,vy.size());
    int b=cal(vy.size(),y+8000,1);


    if(a==1&&b==1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}