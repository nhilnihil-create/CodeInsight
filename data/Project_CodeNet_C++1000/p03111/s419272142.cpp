#include<bits/stdc++.h>

#define swap(type,a,b) {type t; t=a; a=b; b=t;}
#define forN(i,n) for(int i=0;i<n;i++)
#define forS(i,start,n) for(int i=start;i<n;i++)
#define ll long long
#define pb(t,d,n) {t p;int i;forN(i,n){cin>>p;d.push_back(p);}}
#define DOUBLE fixed << setprecision(15)

using namespace std;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;

bool cmp(vi,vi);
int main(){
    int n,m,cnt=0;
    string s;

    int ptr=0;
    int a,b,c;
    cin >>n>>a>>b>>c;
    vi l(n);
    vector<vector<vi>> ret(pow(4,n),vector<vi>(4,vi(2,0)));
    forN(i,n){
        cin >> l[i];
    }
    cnt = 65536;
    forN(i,pow(4,n)){
        int sp=i;
        forN(j,n){
            ret[i][sp&3][0]+=l[j];
            ret[i][sp&3][1]+=10;
            sp>>=2;
        }
        int res1 = abs(a - ret[i][0][0]) + (ret[i][0][1] -10);
        int res2 = abs(b - ret[i][1][0]) + (ret[i][1][1] -10);
        int res3 = abs(c - ret[i][2][0]) + (ret[i][2][1] -10);
        int tmp = res1+res2+res3;
        if(ret[i][0][0]==0||ret[i][1][0]==0||ret[i][2][0]==0){}else{
            cnt=min(tmp,cnt);
        }
    }
    cout << cnt << endl;
}