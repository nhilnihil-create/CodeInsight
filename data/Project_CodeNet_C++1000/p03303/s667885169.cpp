#include<bits/stdc++.h>
using namespace std;

const int mx = 1234567;
const double exp1 = 1e-6;
const int md = 1e9+7;
typedef long long ll;

int ar[mx],xar[mx],uses[mx];
ll arr[mx];
string st[1000];

int main(){

    int tk=1,n,m=0;
//    freopen("in.txt","r", stdin);
//    freopen("out.txt","w", stdout);
    string s;
    while(cin>>s){
        scanf("%d",&n);
        int l = (int)s.size();
        for(int i = 0; i < l; i+=n){
            cout<<s[i];
        }cout<<endl;


    }
    return 0;
}
