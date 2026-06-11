#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m,c;
    cin>>n>>m>>c;
    vector<int>b(m);
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    vector<int>result;
    for(int i=0;i<n;i++)
    {
        int fresult=0;
        for(int j=0;j<m;j++)
        {
            fresult+=(v[i][j]*b[j]);
        }
        fresult+=c;
        result.push_back(fresult);
    }
    int count=0;
    for(int i=0;i<result.size();i++)
    {
        if(result[i]>0){
            count++;
        }
    }
    cout<<count<<endl;
}