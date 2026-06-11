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
int arr[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,m;
    priority_queue<ll>pq;

    cin>>n>>m;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        pq.push(a*-1);
    }
    vector<pair<int,int> >v;
  for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({b,a});
    }
    sort(all(v));
    reverse(all(v));
    for(int i=0;i<m;i++){
        int a=v[i].second,b=v[i].first;
        while(a && (pq.top()*-1)<b){
            pq.pop();
            a--;
            pq.push(b*-1);
        }
    }
    ll sum=0;
    while(!pq.empty()){
        sum+=(pq.top())*-1;
        pq.pop();
    }
    cout<<sum<<endl;



    return 0;
}
