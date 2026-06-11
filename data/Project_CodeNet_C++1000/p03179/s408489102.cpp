#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define for_(i,n) for(int i=0;i<n;++i)
#define for_1(i,n) for(int i=1;i<=n;++i)
const int mod= 1e9 +7;
const int inf=1e7;
int n;
string s;

/*
dp[i][j]:- i th character of permutation is j
we need find sigma over j (dp[n][j])
i range from 0 to n-1

dp[i][j] = dp[i-1][1] + ... +dp[i-1][j-1] if(s[i-1] = '<')
         = dp[i-1][j+1] + ... +dp[i-1][n] if(s[i-1] = '>')
*/
void add_self(int &a, int b)
{
    a+=b;
    if(a>=mod)
    a-= mod;
}


/********************** Recursive Approach ***************************
int dp[3001][3001]; int pre[3001][3001];
int solve(int i, int j){

if(i==1 && j==1){ dp[i][j]=1; return 1;}
//else if(i==1) return 0;
else if(j>i) return 0;
else if(dp[i][j]!=-1) return dp[i][j];
else{
    dp[i][j]=0;
    if(s[i-2]=='<')
    {
        for_1(k,j-1)
        add_self(dp[i][j],solve(i-1,k));
    }
    else if(s[i-2]=='>')
    {
        for(int k=j;k<=n;++k)
        add_self(dp[i][j],solve(i-1,k));
    }
    
   return dp[i][j]; 
}
}

// --------------O(n^3)
*************************************** Recursive Approach ***************/
main()
{
   cin>>n>>s;
   
 /* memset(dp,-1,sizeof(dp));
    int ans=0;
    for_1(i,n)
        add_self(ans,solve(n,i));
    cout<<ans;
 */ 
 
 
 /*********** iterative ***********/
 vector<vector<int>> dpi(n+1,vector<int>(n+1));
 //vector<vector<int>> pref(n+1,vector<int>(n+1));
dpi[1][1]=1;//pref[1][1]=1;

 for(int len =2; len<=n;++len)
 {   
     for(int b =1;b<=len;++b)
     { 
         int l,r;
         if(s[len-2]=='<') l=1,r=b-1;
         else l=b,r=len-1;
         if(l<=r) 
         {
             int tmp = (dpi[len-1][r]+mod-dpi[len-1][l-1])%mod;
             add_self(dpi[len][b],tmp);
         
     
         }
         dpi[len][b] = (dpi[len][b-1] + dpi[len][b]) % mod;
        
         }
 }
/*
int answer = 0;
for(int b = 1; b <= n; ++b) {
    add_self(answer, dpi[n][b]);
    }
    //if extra pref[n+1][n+1] is used
*/
 cout<<dpi[n][n]<<endl;
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










