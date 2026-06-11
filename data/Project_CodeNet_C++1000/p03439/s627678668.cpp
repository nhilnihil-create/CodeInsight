#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
int n,B[200001];
void inout(int x){
    string s;
    cout<<x<<"\n";
    cin>>s;
    if(s=="Vacant") B[x]=-1;
    if(s=="Male") B[x]=1;
    if(s=="Female") B[x]=2;
}
int solve(int x,int y){
    int mid;
    if(x<y) mid=(x+y)/2;
    else mid=(x+y+n)/2;
    inout(mid);
    if(B[mid]==-1) return 0;
    if((y-x+1+n*(x>y))%4==1){
        if(B[x]==B[mid]) solve(mid,y);
        else solve(x,mid);
    }
    else{
        if(B[x]==B[mid]) solve(x,(mid-1+n)%n);
        else solve(mid,(y+1)%n);
    }
}
int main(){
    cin>>n;
    inout(0);
    if(B[0]==-1) return 0;
    solve(0,n-1);
}