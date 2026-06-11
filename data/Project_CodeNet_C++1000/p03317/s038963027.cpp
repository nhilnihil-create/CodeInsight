/*jai_ganeshdeva*/

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pu push  //  adds the value to the last of the queue 
#define lld long long int
#define ins insert /// used in set to insert the values 
#define adv advance  /// used to increment the iterator
#define mp make_pair
#define fi first
#define se second
#define all(c) c.begin(),c.end()
#define PI 3.1415926
#define INF (lld)1e18
#define vl  vector<long long int >
#define vpll vector< pair<lld ,lld> >
#define vvl vector<vector<lld> > 
#define pll pair <lld,lld>
#define modA(cccc,bbbb ,p) (((cccc+bbbb)%p+p)%p)
#define modS(cccc,bbbb ,p) (((cccc-bbbb)%p+p)%p)
#define modM(cccc,bbbb ,p) ((((cccc%p)*(bbbb%p))%p+p)%p)

long long int modp(lld a,lld p,lld n)
{
    lld d[100];
    lld i,j,k,l;
    if(n==0) return 1;
    for(i=0;n>=1;i++)
    {
        d[i]=n%2;
        n/=2;
    }
    l=i;
    long long int e=1;
    if(d[0]==1) e*=(a%p);
    for(i=1;i<l;i++)
    {
        a*=a;
        a=a%p;
        if(d[i]==1) 
        {
            e*=a;
            e=e%p;
        }
    }
    return e%p;
}
lld modInverse(lld n, lld p) 
{ 
    return modp(n, p, p-2); 
}

// lld fac[500005]; 

// void getfac(lld p)
// {
//     fac[0] = 1; 
//     for (lld i=1 ; i<=500005; i++) 
//         fac[i] = fac[i-1]*i%p; 
// }    

// long long int nCrmodp(lld n, lld r,lld p) 
// { 
//    // Base case 
//    if (r==0) 
//       return 1; 
     
//     return (fac[n]* modInverse(fac[r], p) % p * 
//             modInverse(fac[n-r], p) % p) % p; 
// }

// bool sorter(lld a, lld b)
// {
//     vector<lld> v2;
//     vector<lld> w;
//     // cout<<"A == " <<a<<"  B== "<<b;
//     while(a>=1)
//     {
//         v2.pb(a%10);
//         a/=10;
//     }
//     while(b>=1)
//     {
//         w.pb(b%10);
//         b/=10;
//     }   
       
//     reverse(all(v2));
//     reverse(all(w));
//     lld l1 = v2.size();
//     lld l2 = w.size();
//     lld  l = (l1*l2)/__gcd(l1,l2);
//     // cout<<l1<< " "<<l2<< " "<<l<< " ";
//     for(int i=0;i<l;i++)
//     {
//         if(v2[i%l1]!=w[i%l2])
//         {
//             // cout<< "   "<< (v2[i%l1] > w[i%l2])<<"\n";
//             return v2[i%l1] > w[i%l2];
//         }
//     }
//     // printf("false\n");
//     return false;
// }


lld p1=1e9 + 7,p2=998244353;
lld l,r,mid,ans;
lld n,i,j,k,g,m;
lld x,y,n1,n2,h,z,c;
lld aa=1;
lld ss;


void solve()
{
    cin>>n>>k;
    ans=1;
    n-=k;
    while(n>=1)
    {
        n-=(k-1);
        ans+=1;
    }
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t=1;
    
    // cin>>t;
    // cout<<t;
     // getfac(p1);
    //check the value by which modulo is to be taken
    lld ans=0;
    for(int i=0;i<t;i++)
    {
        // cout<<"Case #"<<i+1<<": ";
        solve();
        // cout<<"\n";
    }
    return 0;
}
/*
lld cal_sum(vector<lld> &v ,lld l,lld r,lld x , lld z)
{   
    if(2*z+1> 2*x-1)
    {
        if(z<=r && z>=l) return v[z];
        else return 0;
    }
    if()
}


void solve()
{    
    cin>>n>>m;
    x=1;
    while(x<n)
    {
        x*=2;
    }
    vector<lld> v(2*x-1);
    for(i=0;i<n;i++)
    {
        cin>>v[i+x-1];
    }
    for(i=2*x-2;i>0;i--)
    {
        v[(i-1)/2]+=v[i];
    }
    for(i=0;i<2*x-1;i++)
    {
        cout<<v[i]<< "  ";
    }
    cout<<"\n";
    lld a,b;
    for(i=0;i<m;i++)
    {
        cin>>l>>a>>b;
        if(l==1)
        {
            lld y = b - v[a+x-1];
            a=a+x-1;
            v[a]+=y;
            while(a>0)
            {
                a=(a-1)/2;
                v[a]+=y;
            }
        }
        else
        {
           ans=cal_sum();  
        }
    }
}
*/
