#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int maxprofit=INT_MIN;

void recur(vector<int>v,int index,vector<vector<int>>f,vector<vector<int>>profit)
{
    if(v.size()==10)
    {
        int finalprofit=0;
        int days=0;
        for(int i=0;i<f.size();i++)
        {
            int count=0;
            for(int j=0;j<10;j++)
            {
                if(v[j]==1&&v[j]==f[i][j]){
                    count++;
                }
            }
            finalprofit+=profit[i][count];
            days+=count;
        }
        if(days!=0&&finalprofit>maxprofit)
        {
            maxprofit=finalprofit;
        }
    }
    else
    {
        v.push_back(1);
        recur(v,index+1,f,profit);
        v.pop_back();
        v.push_back(0);
        recur(v,index+1,f,profit);
    }
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>>f(n,vector<int>(10)),profit(n,vector<int>(11));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<10;j++)
        {
            cin>>f[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<11;j++)
        {
            cin>>profit[i][j];
        }
        
    }
    vector<int>v;
    recur(v,0,f,profit);
    cout<<maxprofit;
    
    
    

}