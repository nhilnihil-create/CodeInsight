#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char> >v(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    bool no=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            if(v[i][j]=='#')
            {
                int count=0;
                if(i>0&&v[i-1][j]=='#'){
                    count++;
                }
                if(i<n-1&&v[i+1][j]=='#'){
                    count++;
                }
                if(j>0&&v[i][j-1]=='#'){
                    count++;
                }
                if(j<m-1&&v[i][j+1]=='#'){
                    count++;
                }
                if(count==0)
                {
                    no=true;
                    break;
                }
            }
            if(no)
            {
                break;
            }
        }
    }
    if(no){
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }
}