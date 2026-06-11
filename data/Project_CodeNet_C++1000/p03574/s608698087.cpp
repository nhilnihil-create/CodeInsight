#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char element;
            cin>>element;
            if(element=='#')
            {
                v[i][j]=-1;
            }
            else
            {
                v[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j]==-1)
            {
                if(i>0&&v[i-1][j]!=-1)
                {
                    v[i-1][j]++;
                }
                if(i<n-1&&v[i+1][j]!=-1)
                {
                    v[i+1][j]++;
                }
                if(j<m-1&&v[i][j+1]!=-1)
                {
                    v[i][j+1]++;
                }
                if(j>0&&v[i][j-1]!=-1)
                {
                    v[i][j-1]++;
                }
                if(i>0&&j>0&&v[i-1][j-1]!=-1)
                {
                    v[i-1][j-1]++;
                }
                if(i>0&&j<m-1&&v[i-1][j+1]!=-1)
                {
                    v[i-1][j+1]++;
                }
                if(i<n-1&&j>0&&v[i+1][j-1]!=-1)
                {
                    v[i+1][j-1]++;
                }
                if(i<n-1&&j<m-1&&v[i+1][j+1]!=-1)
                {
                    v[i+1][j+1]++;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j]==-1)
            {
                cout<<"#";
                continue;
            }
            cout<<v[i][j];
        }
        cout<<endl;
    }
}