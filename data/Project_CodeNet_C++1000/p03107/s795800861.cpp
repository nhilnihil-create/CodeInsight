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

int main(){
    int n,m,cnt=0;
    string s;

    cin >> s;
    int p=0,tmp=0;
    forN(i,s.size()){
        if(s[i]=='1'){
            tmp++;
        }else{
            tmp--;
        }
        if(abs(p)-abs(tmp)>0) cnt++;
        p=tmp;
    }
    cout << cnt*2 << endl;
}
