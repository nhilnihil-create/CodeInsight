// by The_One_Solver
#include <bits/stdc++.h>
using namespace std;
/*
long long n;
vector<vector<pair<long long ,long long > > > v(1000);
struct node
{
    int num,dist;
    node()
    {
        num=0;dist=1e9;
    }
    node(int c,int x)
    {
        this->num=c;
        this->dist=x;
    }
};
const int N=100000;
int dist[N];
void dijkstra(int m)
{
    memset(dist,1e9,N);
    dist[m]=0;
    priority_queue<node> pq;
    pq.push(node(m,dist[m]));


}
*/
const int N=1e5;
long long  n,k,arr[N];
string str;
int main()
{
    cin>>n>>k;
    cin>>str;
    /*
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
   */
   int coun=0;
   for(int i=1;i<str.size();i++)
   {
     if(str[i]=='C'&&str[i-1]=='A')
      {
          arr[i]=arr[i-1]+1;
      }
     else arr[i]=arr[i-1];
   }

    for(int i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<arr[b-1]-arr[a-1]<<endl;
    }


}
