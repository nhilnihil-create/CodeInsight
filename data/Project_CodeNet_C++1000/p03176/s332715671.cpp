#include <bits/stdc++.h>
using namespace std;
#define int long long
#define for_(i,n) for(int i=0;i<n;++i)
const int mod= 1e9 +7;
const int inf=1e7;
int n;



void updateTreeNode(vector<int> & tree,int p, int value)  
{  
    // set value at position p 
    tree[p+n] = value; 
    p = p+n; 
      
    // move upward and update parents 
    for (int i=p; i > 1; i >>= 1) 
        tree[i>>1] = max(tree[i],tree[i^1]); 
} 
  
// function to get sum on interval [l, r) 
int query(vector<int> & tree,int l, int r)  
{  
    int res = -inf; 
      
    // loop to find the sum in the range 
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
    { 
        if (l&1)  
            res = max(res,tree[l++]); 
      
        if (r&1)  
            res = max(res,tree[--r]); 
    } 
      
    return res; 
} 


main()
{  
 cin>>n;
int h[n],a[n];
for_(i,n) cin>>h[i];
for_(i,n) cin>>a[i];
int dp[n];
//vector<int> dp(n+1, inf);
/*
LIS::
dp[i] = length of increasing subsequence when it ends at arr[i]
		     	Recurrence relation:	dp[i] = max(1,  max(dp[j] +1));
 where j: 0,1… i-1 and arr[j]<arr[i]
Modify LIS to accomodate beauty value

*/
vector<int> tree(2*n+2, -inf);
int ans=dp[0]= a[0];
updateTreeNode(tree,h[0],dp[0]);                                  

for(int i=1;i<n;++i)
{   
dp[i] = max(a[i],query(tree,1,h[i])+a[i]);
updateTreeNode(tree,h[i],dp[i]);
ans=max(ans,dp[i]);
  
}
cout<<ans<<endl;

    
}























/*
typedef struct structure{
    int x,y;
} pt;
pt p0;
bool cmp(pt a, pt b)
{
    return cw(p0,a,b);
}
bool cw(pt a, pt b, pt c){
    return ((c.y-a.y)*(b.x-a.x)-(b.y-a.y)*(c.x-a.x))>=0
}



convex_hull(vector<pt>& points)
{
   // sort(points.begin(),points.end, cmp);// sorted according to y cordinate
    p0=points[0];
    sort(points.begin(),points.end, cmp);
    vector<pt> convexHull;
    stack<pt> temp;
    convexHull.push_back(points[0]);
    
    temp.push(points[0]);temp.push(points[1]);//temp.push(points[2]);
    pt top,top0;
    for(int it=2;it<points.size();++it)
    {   
        top=temp.top(); temp.pop(); top0=temp.top();
        pt next=points[it];
        if(cw(top0,top,next))
        {
            convexHull.push_back(top);
            temp.push(top);
            top0=top;
            top=next;
        }
        else
        {
          temp.push(next);  
        }
        
    }
    
}*/










