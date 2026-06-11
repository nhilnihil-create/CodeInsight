#include<bits/stdc++.h>
using namespace std;

#define sz 100005
#define ff first
#define ss second
#define nl printf("\n");
#define ll long long int

char f,g;
bool flag;
pair < int ,int > pi;
map < int , int > mp;
vector < pair < int , pair < int, int > > > v,va,vb;
vector < pair < int , pair < int, int > > > vp;
//vector < pair < int, int > > vp;
int arr[sz],brr[sz],crr[sz];

int digitof(int x){
    int cnt=0;
    while(x){
        x/=10;
        cnt++;
    }
    return cnt;
}

int main(){

    int n,m, i,j,k, x=0,y=0,z=0, a,b,c;

    cin>>n>>m;
    for(i=0; i<m; i++){
        cin>>a>>b;
        v.push_back({b,{a,i}});
        ///cout<<v[i].ff<<' '<<v[i].ss.ff<<' '<<v[i].ss.ss<<endl;
    }
    sort(v.begin(),v.end());

    for(i=0; i<m; i++){

       a=v[i].ss.ff;///num
       b=v[i].ss.ss;///index
       //cout<<a<<' '<<b<<
       mp[a]++;
       vp.push_back({b,{a,mp[a]}});
    }
    sort(vp.begin(),vp.end());

    for(i=0; i<m; i++){

        x=vp[i].ss.ff;
        y=6-digitof(x);

        while(y--)cout<<0;
        cout<<x;

        x=vp[i].ss.ss;
        y=6-digitof(x);

        while(y--)cout<<0;
        cout<<x<<endl;
    }

    return 0;

}