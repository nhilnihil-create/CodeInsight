#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int arr[MAX],segment_tree[MAX];
void Construct_Tree(int low,int high,int pos)
{
    if(low==high)
    {
        segment_tree[pos]=arr[low];
        return ;
    }
    int mid=(low+high)/2;
    Construct_Tree(low,mid,pos*2+1);
    Construct_Tree(mid+1,high,pos*2+2);
    segment_tree[pos]=__gcd(segment_tree[2*pos+1],segment_tree[2*pos+2]);
}
int Range_min_query(int st,int en,int low,int high,int pos)
{

    if(st<=low && en>=high)
        return segment_tree[pos];//total overlap

    if(st>high || en<low)
        return 0;// no overlap

    int mid=(low+high)/2;

    return __gcd(Range_min_query(st,en,low,mid,2*pos+1),Range_min_query(st,en,mid+1,high,2*pos+2));
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int mx=1;
    Construct_Tree(0,n-1,0);
    for(int i=0; i<n; i++)
    {
        int l=Range_min_query(0,i-1,0,n-1,0);
        int r=Range_min_query(i+1,n-1,0,n-1,0);
        mx=max(mx,__gcd(l,r));
    }
    cout<<mx<<endl;


    return 0;
}
