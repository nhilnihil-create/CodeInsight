# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
int n,a,b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>a>>b;
    if((b-a)%2==0){
        cout<<"Alice"<<endl;
    }
    else cout<<"Borys"<<endl;
}