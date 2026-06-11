#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
//HDU 627235
//USACO bc083db
//timus 251103FD 
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define Forn(i, n) for(int i=1; i<=(n); i++)
#define forn(i, n) for(int i=0; i<(n); i++)
#define Foreach(it, a) for(__typeof((a).rbegin()) it=(a).rbegin(); it!=(a).rend(); it++)
#define foreach(it, a) for(__typeof((a).begin()) it=(a).begin(); it!=(a).end(); it++)
/*
    Chasing after you is like a fairytale
    But I 
    Feel like I'm glued on tight
    To this carousel
    
    4008802802 
*/

const int MAX=2e5+5;

int N, ptr, A[MAX];
map<int,int> tmp;

int check(int x)
{
    tmp.clear();
    Forn(i, N-1)
    {
        int dlt=A[i]-A[i-1];
        if(dlt>0) continue;
        map<int,int>::iterator ii=tmp.upper_bound(A[i]);
        tmp.erase(ii, tmp.end());
        int tag=0;
        for(int j=A[i]; j>0; j--)
            if(tmp[j]<x)
            {
                tmp[j]++;
                tag=1;
                break;
            }
            else tmp.erase(tmp.find(j));
//        foreach(it, tmp) cout<<it->f<<" "<<it->s<<endl;
        if(!tag) return 0;
    }
    return 1;
}

void pd()
{
    int tag=1;
    forn(i, N-1) if(A[i+1]<=A[i])
        tag=0;
    if(tag) puts("1"), exit(0);
}

int main()
{
    scanf("%d", &N);
    forn(i, N) scanf("%d", &A[i]);
    pd();
    int l=0, r=1e9;
    while(l+1<r)
    {
        int m=l+r>>1;
        if(check(m)) r=m;
        else l=m;
    }
    printf("%d\n", r+1);
//    cout<<check(2)<<endl;
    return 0;
}