#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define mp(a,b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define ll long long
int main() {
    int N;
    cin>>N;
    int ar[N];
    int ar2[N];
    REP(i,N)
    {
        cin>>ar[i];
    }
    REP(i,N)
    {
        cin>>ar2[i];
    }int c=0;
    REP(i,N)
    {
        if(ar[i]>ar2[i])
        c+=ar[i]-ar2[i];
    }
    cout<<c<<endl;
}
    