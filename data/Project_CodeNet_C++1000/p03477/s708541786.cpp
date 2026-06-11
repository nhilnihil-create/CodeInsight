#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(inti=a;i<=b;i++)

#define MOD 1000000007
typedef long long int ll;
typedef vector<int>vi;
typedef pair<int,int>pi;


int main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);
int a,b,c,d;
cin>>a>>b>>c>>d;

if(a+b<c+d)
    cout<<"Right"<<endl;
else if(a+b>c+d)
    cout<<"Left"<<endl;
else
    cout<<"Balanced"<<endl;

 return 0;
}
