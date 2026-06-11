#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mxn= 5e4+5;
// check for forloop
// intialize variable
// overflow
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
//#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int arr[mxn],n;
int query(int x, int y){
    cout<<"? "<<x<<' '<<y<<endl;
    int val;
    cin>>val;
    return val;
}
void print(){
    cout<<"! ";
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}
int main(){
    rishabh();
    cin>>n;
    int prex, prey, pret;
    prex=prey=pret=0;
    for(int i=0;i<n;i++){
        int t,x,y;
        cin>>t>>x>>y;
        if(t-pret>=abs(x-prex)+abs(y-prey)&&((t-pret)%2==(abs(x-prex)+abs(y-prey))%2)){
            prex=x;
            prey=y;
            pret=t;
            continue;
        }
        else {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}