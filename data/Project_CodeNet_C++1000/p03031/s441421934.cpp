#include<bits/stdc++.h>

#define swap(type,a,b) {type t; t=a; a=b; b=t;}
#define forN(i,n) for(int i=0;i<n;i++)
#define forS(i,start,n) for(int i=start;i<n;i++)
#define ll long long
#define pb(t,d,n) {t p;int i;forN(i,n){cin>>p;d.push_back(p);}}
#define DOUBLE fixed << setprecision(10)

using namespace std;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;

int main(){
    int n,m,i=0,j=0,cnt=0;
    
    cin >> n >> m;
    vector<vector<int>> k(m);
    forN(i,m){
        int tmp;cin >> tmp;
        k[i] = vector<int>(tmp);
        forN(j,k[i].size()){
            cin >> k[i][j];
            k[i][j] -= 1;
        }
    }
    vi p(m);
    forN(i,m){
        cin >> p[i];
    }
    vector<int> s(n);
    forN(i,pow(2,n)){
        bool res=true;
        int tmp = i;
        for(int j=0; j<n; j++){
            s[j] = (int)(tmp&1);
            tmp >>= 1;
        }
        forN(j,m){
            int tmp = 0;
            forN(l,k[j].size()){
                tmp += s[k[j][l]];
            }
            tmp+=(p[j]+1);
            res&=(tmp&1);
        }
        if(res)cnt++;
    }
    cout << cnt << endl;
}