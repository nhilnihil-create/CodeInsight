#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define DL double
#define MLL map<LL,LL>::iterator
#define MSL map<string,L>::iterator
#define MLS map<LL,string>::iterator
#define MSS map<string,string>::iterator
#define MCL map<char,LL>::iterator
#define SL set<LL>::iterator
#define SS set<string>::iterator
#define VL vector<LL>::iterator
#define G getline
#define SZ size()
#define IN insert
#define C clear()
#define B begin()
#define F front()
#define T top()
#define E end()
#define EM empty()
#define V vector
#define Q queue
#define DQ deque
#define PQ priority_queue
#define ST stack
#define FI first
#define SE second
#define PI acos(-1)
#define PS push
#define PP pop()
#define PSF push_front
#define PSB push_back
#define PPF pop_front()
#define PPB pop_back()
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
V<pair<LL,pair<LL,LL> > >v;
int main()
{
    FAST;
    LL n,m,i,j,k,p,q,o,l,s,t,z;
    cin>>n>>m;
    if(m==1 && n==1)
    {
        cout<<1<<endl;
    }
    else if(n==2 || m==2)
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<max((LL)1,n-2)*max((LL)1,m-2)<<endl;
    }
    return 0;
}
