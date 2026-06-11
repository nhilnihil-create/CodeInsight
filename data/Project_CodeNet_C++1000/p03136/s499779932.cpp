#include<bits/stdc++.h> 
#include<random>
#define int long long   
#define pp pair<int,int> 
#define ss second 
#define ff first 
#define pb push_back
#define mod 1000000007
#define mk(arr,n,type)  type *arr=new type[n];
#define sl s1.length();
#define yes cout<< "Yes"<<endl
#define no  cout<< "No"<<endl
#define all(v) (v).begin(),(v).end()
#define  mt mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;    
void fastio()
{  
  #ifndef ONLINE_JUDGE
  freopen("INPUT.txt","r",stdin);
  freopen("OUTPUT.txt","w",stdout); 
  #endif
  ios_base :: sync_with_stdio(false); 
  cin.tie(NULL) ; 
  cout.tie(NULL);
}
signed main()
{   
    fastio();
    int t=1;
   // cin>>t;
    while(t--)
    { 
        int n,sum=0;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        sort(a,a+n);
        for(int i=0;i<n-1;i++)
        {
            sum+=a[i];
        }
        if(sum>a[n-1])
        cout<<"Yes";
        else
        cout<<"No";
    }
    
}
// 🍪 🍪 🍪