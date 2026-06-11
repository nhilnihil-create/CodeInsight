#include<bits/stdc++.h>
using namespace std;
#define int long long int 


struct BIT 
{
    int bit_tree[100005];
    public:
    BIT()
    {
        memset(bit_tree,0,sizeof(bit_tree));
    }

    void update(int index,int value)
    {
            while(index<100005)
            {
                bit_tree[index]+=value;
                index+=(index&(-index));
            }
    }

    int get(int index)
    {
        int sum=0;
        while(index>0)
        {
            sum+=bit_tree[index];
            index-=(index&(-index));
        }
        return sum;
    }
};
int32_t main()
{
    int n,m;
    cin>>n>>m;

    vector<array<int,2>> graph;
    for(int i=0;i<m;i++)
    { 
        int x,y;
        cin>>x>>y;
        graph.push_back({y,x});
    }
    sort(graph.begin(),graph.end());
    //  for(int i=0;i<m;i++)
    //  {
    //      cout<<graph[i][0]<<" "<<graph[i][1]<<endl;
    //  }
    struct BIT bit;
    int ans=0;
    for(int i=0;i<m;i++)
    {
        int x=bit.get(graph[i][0])-bit.get(graph[i][1]);
        if(x==0)
        {

             bit.update(graph[i][0],1); 
             ans++;
        }
    }
    cout<<ans<<endl;



}