#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define per1(i,n) for(int i=n;i>0;i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
struct ans{int u,v,d;};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int L;
    cin>>L;
    if(L==2){
        cout<<2<<" "<<2<<"\n";
        cout<<"1 2 0\n";
        cout<<"1 2 1\n";
        return 0;
    }
    L--;
    int n=log2(L)+1;
    vector<ans> ANS;
    rep1(i,n-1) ANS.push_back({i,i+1,0}),ANS.push_back({i,i+1,(int)pow(2,n-i-1)});
    while(L>=pow(2,n-1)){
        int a=0,b=0;
        while(L-(b+pow(2,a))>=pow(2,n-1)&&a<n-2) b+=pow(2,a),a++;
        ANS.push_back({1,n-a,L-b});
        L-=b+1;
    }
    cout<<n<<" "<<ANS.size()<<"\n";
    for(auto i:ANS) cout<<i.u<<" "<<i.v<<" "<<i.d<<"\n";
}