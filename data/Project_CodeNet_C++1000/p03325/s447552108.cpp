#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb push_back;
#define sp " ";
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    int ans=0,n;
    cin>>n;
    rep(i,n){
        int ai;
        cin>>ai;
        while(true){
            if(ai%2==0){
                ans+=1;
                ai/=2;
            }
            else{break;}
        }
    }
    cout<<ans;
}