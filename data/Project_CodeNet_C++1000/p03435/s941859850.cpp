#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>>a(3,vector<int>(3));
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
    bool no=false;
    for(int i=0;i<2;i++)
    {
        int f=-1,s=-1;
        for(int j=0;j<=2;j++)
        {
            if(f==-1)
            {
                f=a[i+1][j]-a[i][j];
                s=a[j][i+1]-a[j][i];
            }
            if(a[i+1][j]-a[i][j]!=f){
                no=true;
                break;
            }
            if(s!=a[j][i+1]-a[j][i]){
                no=true;
                break;
            }
        }
        if(no)
        {
            break;
        }
    }
    if(no)
    {
        cout<<"No\n";
    }
    else
    {
        cout<<"Yes\n";
    }
}