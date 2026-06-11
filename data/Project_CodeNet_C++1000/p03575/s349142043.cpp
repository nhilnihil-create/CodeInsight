#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>vp[n];
    for(int i=0;i<m;i++)
    {
        int f,s;
        cin>>f>>s;
        f--;s--;
        vp[f].push_back(s);
        vp[s].push_back(f);
    }
    vector<int>count(n,0);
    for(int i=0;i<n;i++)
    {
        count[i]=vp[i].size();
    }
    queue<int>q;
    vector<bool>visited(n,false);
    for(int i=0;i<count.size();i++)
    {
        if(count[i]==1)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int element=q.front();
        q.pop();    
        visited[element]=true;
        count[element]=0;
        for(int i=0;i<vp[element].size();i++)
        {
            if(!visited[vp[element][i]])
            {
                if(count[vp[element][i]]==2){
                    q.push(vp[element][i]);
                }
                else
                {
                    count[vp[element][i]]--;
                }
            }
        }
    }
    int finalcount=0;
    for(int i=0;i<n;i++)
    {
        finalcount+=count[i];
    }
    cout<<m-finalcount/2;
}